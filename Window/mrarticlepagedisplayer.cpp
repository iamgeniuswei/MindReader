/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArticlePage.cpp
 * Author: develop
 *
 * Created on October 12, 2018, 8:15 AM
 */

#include "mrarticlepagedisplayer.h"
#include "private/mrarticlepagedisplayer_p.h"
#include <QMouseEvent>
#include "mrpage.h"
#include "PDFUtil.h"
#include <QDebug>
#include <QPainter>
#include <QPaintEngine>
#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include <QKeyEvent>
#include "articlepagerender.h"
#include <QPixmapCache>
#include "mrcursor.h"
#include "mrannotationcreator.h"
#include "mrarticlepagepainter.h"
#include "mrocrrecognizer.h"
MRArticlePageDisplayer::MRArticlePageDisplayer(QWidget *parent)
    :QLabel(parent), d(new (std::nothrow) MRArticlePageDisplayerPrivate)
{
    setScaledContents (true);
    setMouseTracking (true);
    //grabKeyboard ();
    loadSignals ();
}

MRArticlePageDisplayer::~MRArticlePageDisplayer()
{
}

void MRArticlePageDisplayer::setMRPage(std::shared_ptr<MRPage> &src)
{
    Q_ASSERT (d != nullptr );
    d->page.reset ();
    d->page = src;
    d->annotsOnDraw.clear ();
    d->annotsInPage.clear ();
    Q_ASSERT (d->page);
    QList<SPtrMRA> &&annots = d->page->getAnnotations ();
    d->annotsInPage = std::move(annots);
}

int MRArticlePageDisplayer::pageIndex() const
{
    Q_ASSERT (d!=nullptr);
    return d->pageIndex;
}

void MRArticlePageDisplayer::setAnnotationFlag(int flag)
{
    Q_ASSERT ( d != nullptr );
    d->annotFlag = flag;
}

void MRArticlePageDisplayer::setCursorType(CURSOR cursor)
{
    Q_ASSERT ( d != nullptr );
    d->cursor_ = cursor;
}

void MRArticlePageDisplayer::setPageIndex(int index)
{
    Q_ASSERT (d != nullptr );
    d->pageIndex = index;
}

void MRArticlePageDisplayer::displayPage(float scaleX, float scaleY, float rotation, int index, QImage img, std::shared_ptr<MRPage> page)
{
    Q_ASSERT (d != nullptr );
    d->scaleX = scaleX;
    d->scaleY = scaleY;
    d->rotation = rotation;
    d->pageIndex = index;

    QPixmap pixmap = QPixmap::fromImage (img);
    d->pageSize.setHeight (pixmap.height ());
    d->pageSize.setWidth (pixmap.width ());
    setPixmap (pixmap);
    resize (sizeHint ());
    setMRPage (page);
}

void MRArticlePageDisplayer::requestPage(int index, float scaleX, float scaleY, float rotation)
{
    Q_ASSERT (d != nullptr );
    Q_ASSERT ( d->render != nullptr );
    d->render->requestPage (index,
                         scaleX,
                         scaleY,
                         rotation);
}





void MRArticlePageDisplayer::mousePressEvent(QMouseEvent* event)
{
    Q_ASSERT (d != nullptr );
    d->mouseStartPoint = event->pos ();
    d->isDrawFollowMouse = true;
}

void MRArticlePageDisplayer::mouseMoveEvent(QMouseEvent *event)
{
    Q_ASSERT (d != nullptr );
    d->mouseEndPoint = event->pos ();
    if(d->isShiftDown)
    {
        d->mouseEndPoint.setY (d->mouseStartPoint.y ());
    }
    update ();
}

void MRArticlePageDisplayer::mouseReleaseEvent(QMouseEvent* event)
{
    Q_ASSERT (d != nullptr );
    d->isDrawFollowMouse = false;
    d->mouseEndPoint = event->pos ();

    if(d->cursor_ == CURSOR::SELECT)
    {
        appendAnnotation ();
        QString str = getTextFromSelection ();
        if(!str.isEmpty ())
            emit textReady (d->pageIndex, str);
//        if(!str.isEmpty ())
//            emit textReady (d->pageIndex, str);
//        else {
//            grabRectangle ();
//        }

    }
    else
    {
        appendAnnotation ();
    }
    update ();
}

void MRArticlePageDisplayer::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent (event);
    QPainter painter(this);    

    if(d->isDrawFollowMouse)
    {
        MRArticlePagePainter::drawFollowMouse (painter,
                                               d->curColor,
                                               d->cursor_,
                                               d->mouseStartPoint,
                                               d->mouseEndPoint);
    }

    for(int i=0; i< d->annotsOnDraw.size (); i++)
    {

        std::shared_ptr<MRAnnotation> tmp = d->annotsOnDraw.at (i);
        Q_ASSERT (tmp != nullptr);
        tmp->draw (painter, d->scaleX, d->scaleY, d->rotation);
    }
}

void MRArticlePageDisplayer::keyPressEvent(QKeyEvent *event)
{
    Q_ASSERT ( d != nullptr );
    if(event->modifiers () == Qt::ShiftModifier)
    {
        d->isShiftDown = true;
    }
}

void MRArticlePageDisplayer::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED (event);
    Q_ASSERT ( d != nullptr );
    d->isShiftDown = false;
}

void MRArticlePageDisplayer::appendAnnotation()
{
    switch (d->annotFlag)
    {
    case PDF_ANNOT_LINE:
    {
        appendLineToPage ();
    }
        break;
    case PDF_ANNOT_SQUARE:
    {
        appendSquareToPage ();
    }
        break;
    case PDF_ANNOT_HIGHLIGHT:
    {
        appendHighlightToPage ();
    }
        break;
    case PDF_ANNOT_TEXT:
        break;
    }
}



QPixmap &&MRArticlePageDisplayer::grabRectangle()
{
    QRect rect = calculateSelectionRect ();
    QPixmap p = this->grab(rect);
    emit selectionReady (d->pageIndex, p);
//    d->ocr->addPendingPix (p);
    return std::move(p);
}

void MRArticlePageDisplayer::appendLineToPage()
{
    SPtrMRA annotation = nullptr;
    fz_point *points = new fz_point[2];
    if(d->isShiftDown)
    {
        points[0].x = d->mouseStartPoint.x ();
        points[0].y = d->mouseStartPoint.y ();
        points[1].x = d->mouseEndPoint.x ();
        points[1].y = d->mouseStartPoint.y ();
    }
    else
    {
        points[0].x = d->mouseStartPoint.x ();
        points[0].y = d->mouseStartPoint.y ();
        points[1].x = d->mouseEndPoint.x ();
        points[1].y = d->mouseEndPoint.y ();
    }

    mapToOrigin (*points, d->scaleX, d->scaleY, d->rotation);
    mapToOrigin (*(points+1), d->scaleX, d->scaleY, d->rotation);
    float color[3] {static_cast<float>(d->curColor.redF ()),
                static_cast<float>(d->curColor.greenF ()),
                static_cast<float>(d->curColor.blueF ())};
    annotation = d->page->addAnnotation (d->annotFlag, points, color);
    delete [] points;
    if(annotation != nullptr)
        d->annotsOnDraw.append (annotation);
}

void MRArticlePageDisplayer::appendSquareToPage()
{
    SPtrMRA annotation = nullptr;
    fz_rect *rect = new fz_rect;
    rect->x0 = d->mouseStartPoint.x ();
    rect->y0 = d->mouseStartPoint.y ();
    rect->x1 = d->mouseEndPoint.x ();
    rect->y1 = d->mouseEndPoint.y ();
    mapToOrigin (*rect, d->scaleX, d->scaleY, d->rotation);
    float color[3] {static_cast<float>(d->curColor.redF ()),
                static_cast<float>(d->curColor.greenF ()),
                static_cast<float>(d->curColor.blueF ())};
    annotation = d->page->addAnnotation (d->annotFlag, rect, color);
    delete rect;
    if(annotation != nullptr)
        d->annotsOnDraw.append (annotation);
}

void MRArticlePageDisplayer::appendHighlightToPage()
{
    SPtrMRA annotation = nullptr;
    QRect srect = calculateSelectionRect ();
    fz_rect *rect = new fz_rect;
    rect->x0 = srect.topLeft ().x ();
    rect->y0 = srect.topLeft ().y ();
    rect->x1 = srect.bottomRight ().x ();
    rect->y1 = srect.bottomRight ().y ();

    mapToOrigin (*rect, d->scaleX, d->scaleY, d->rotation);
    fz_quad *quad = new fz_quad[200];
    int num = 0;
    d->page->getSelectionQuads (*rect, quad, num);
    float color[3] {static_cast<float>(d->curColor.redF ()),
                static_cast<float>(d->curColor.greenF ()),
                static_cast<float>(d->curColor.blueF ())};
    for(int i=0; i<num; i++)
    {
        annotation = d->page->addAnnotation (d->annotFlag, (quad+i), color);
        if(annotation != nullptr)
            d->annotsOnDraw.append (annotation);
    }
    delete rect;
    delete [] quad;

}

QSize MRArticlePageDisplayer::pageSize() const
{
    return d->pageSize;
}

void MRArticlePageDisplayer::handleCursorType(CURSOR cursor)
{
    MRCursor::setCursor (this, cursor);
}

void MRArticlePageDisplayer::updateColor(const QColor &color)
{
    if(color.isValid ())
        d->curColor = color;
}

void MRArticlePageDisplayer::setImage(const QImage &img)
{
    this->setPixmap (QPixmap::fromImage (img));
    update ();
}

QString MRArticlePageDisplayer::getTextFromSelection()
{
    Q_ASSERT (d != nullptr );
    Q_ASSERT ( d->page != nullptr );
    QRect srect = calculateSelectionRect ();
    fz_rect rect;
    rect.x0 = srect.topLeft ().x ();
    rect.y0 = srect.topLeft ().y ();
    rect.x1 = srect.bottomRight ().x ();
    rect.y1 = srect.bottomRight ().y ();

    rect = mapToOrigin (rect, d->scaleX, d->scaleY, d->rotation);
    QString str = d->page->getSelectionText (rect);
    return str;
}

QRectF MRArticlePageDisplayer::calculateSelectionRectF()
{
    Q_ASSERT ( d != nullptr );
    qreal x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    if (d->mouseEndPoint != d->mouseStartPoint)
    {
        if (d->mouseStartPoint.x() > d->mouseEndPoint.x())
        {
            x0 = d->mouseEndPoint.x();
            x1 = d->mouseStartPoint.x();
        } else {
            x0 = d->mouseStartPoint.x();
            x1 = d->mouseEndPoint.x();
        }
        if (d->mouseStartPoint.y() > d->mouseEndPoint.y()) {
            y0 = d->mouseEndPoint.y();
            y1 = d->mouseStartPoint.y();
        } else {
            y0 = d->mouseStartPoint.y();
            y1 = d->mouseEndPoint.y();
        }
    }
    QRectF rect(x0, y0, x1 - x0, y1 - y0);
    return rect;
}

QRect MRArticlePageDisplayer::calculateSelectionRect()
{
    Q_ASSERT ( d != nullptr );
    int x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    if (d->mouseEndPoint != d->mouseStartPoint)
    {
        if (d->mouseStartPoint.x() > d->mouseEndPoint.x())
        {
            x0 = d->mouseEndPoint.x();
            x1 = d->mouseStartPoint.x();
        } else {
            x0 = d->mouseStartPoint.x();
            x1 = d->mouseEndPoint.x();
        }
        if (d->mouseStartPoint.y() > d->mouseEndPoint.y()) {
            y0 = d->mouseEndPoint.y();
            y1 = d->mouseStartPoint.y();
        } else {
            y0 = d->mouseStartPoint.y();
            y1 = d->mouseEndPoint.y();
        }
    }
    QRect rect(x0, y0, x1 - x0, y1 - y0);
    return rect;
}


//TODO:重载了paintEvent事件处理函数后，QLabel的size出现了问题:
//1)自绘制区域没有得到空间，使用sizeHint（）得到解决，但是实际问题机理尚不明确。

//QSize ArticlePage::sizeHint() const
//{
//    return QSize(1200,1200);
//}

float MRArticlePageDisplayer::getScaleX() const
{
    Q_ASSERT ( d != nullptr );
    return d->scaleX;
}

void MRArticlePageDisplayer::setScaleX(float value)
{
    Q_ASSERT ( d != nullptr );
    d->scaleX = value;
}

float MRArticlePageDisplayer::getScaleY() const
{
    Q_ASSERT ( d != nullptr );
    return d->scaleY;
}

void MRArticlePageDisplayer::setScaleY(float value)
{
    Q_ASSERT ( d != nullptr );
    d->scaleY = value;
}

void MRArticlePageDisplayer::setDoc(std::shared_ptr<MRDocument> value)
{
    Q_ASSERT (d != nullptr);
    d->doc = value;
//    d->render->setPDFDocument (value);
}

void MRArticlePageDisplayer::loadSignals()
{
    Q_ASSERT (d != nullptr);
//    d->render = new ArticlePageRender(this);
//    connect (d->render, &ArticlePageRender::pageReady,
//             this, &MRArticlePageDisplayer::displayPage);
//    d->ocr = new MROCRRecognizer(this);
//    d->ocr->start ();

}

