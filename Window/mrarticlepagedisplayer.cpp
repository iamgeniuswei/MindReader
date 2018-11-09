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
    grabKeyboard ();
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
    d->annotations.clear ();
    Q_ASSERT (d->page);
    d->page->getAnnotations(d->annotations);
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
        QString str = getTextFromSelection ();
        if(!str.isEmpty ())
            emit textReady (d->pageIndex, str);
        else {
            grabRectangle ();

        }
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
                                               d->cursor_,
                                               d->mouseStartPoint,
                                               d->mouseEndPoint);
    }

//    qDebug() << d->annotations.size ();

    for(int i=0; i< d->annotations.size (); i++)
    {

        std::shared_ptr<MRAnnotation> tmp = d->annotations.at (i);
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

void MRArticlePageDisplayer::drawAnnotations(QPainter &painter)
{
//    for(int i=0; i<annotations.size (); i++)
//    {
//        MRAnnotation tmp = annotations.at (i);
//        switch (tmp.getType ())
//        {
//        case PDF_ANNOT_LINE:
//            drawLine (painter, tmp);
//            break;
//        case PDF_ANNOT_SQUARE:
//            break;
//        case PDF_ANNOT_HIGHLIGHT:
//            break;
//        default:
//            break;
//        }
//    }
}

void MRArticlePageDisplayer::drawLine(QPainter& painter)
{
////    QPainter painter;
//    painter.begin (this);
//    QPen pen(Qt::red, 2);
//    painter.setPen (pen);
//    painter.setRenderHint (QPainter::Antialiasing);
//    painter.drawLine (startPoint, endPoint);
//    painter.end ();
}

void MRArticlePageDisplayer::drawLine(QPainter &painter, const MRAnnotation &annotation)
{

//    fz_rect rect = mapFromOrigin (annotation.getRect (),
//                                  scaleX,
//                                  scaleY,
//                                  rotation);

//    QPointF start(rect.x0, rect.y0);
//    QPointF end(rect.x1, rect.y1);

////    QPainter painter;
//    painter.begin (this);
//    QPen pen(Qt::red, 2);
//    painter.setPen (pen);
//    painter.setRenderHint (QPainter::Antialiasing);
//    painter.drawLine(start, end);
//    painter.end ();
}

void MRArticlePageDisplayer::drawSelectionFollowMouse(QPainter &painter)
{
//    painter.begin (this);
//    QRect rect(startPoint, endPoint);
//    painter.fillRect (rect, QBrush(QColor(18, 150, 219, 100)));
//    painter.end();
}

void MRArticlePageDisplayer::drawSelection(QPainter &painter, const MRAnnotation &annot)
{

//    painter.begin (this);
//    fz_rect rect = mapFromOrigin (annot.getRect (),
//                                  scaleX,
//                                  scaleY,
//                                  rotation);
//    QRectF qrect(QPointF(rect.x0,rect.y0),
//                QPointF(rect.x1, rect.y1));
//    painter.fillRect (qrect,
//                      QColor(18, 150, 219, 100));
////    for(int i=0; i<quads_list.size (); i++)
////    {
////        fz_quad quad = quads_list.at (i);
////        QRectF rect = QRectF(quad.ul.x, quad.ul.y, quad.lr.x - quad.ll.x, quad.lr.y - quad.ul.y);
////        rect = mapFromOrigin (rect, scaleX, scaleY, rotation);
////        painter.fillRect (rect,
////                          QColor(18, 150, 219, 100));
////    }
//    painter.end ();
}

void MRArticlePageDisplayer::drawRectangleFollowMouse(QPainter &painter)
{
//    painter.begin (this);
//    QPen pen(Qt::red, 2);
//    painter.setPen (pen);
//    painter.setRenderHint (QPainter::Antialiasing);
//    QRect rect(startPoint, endPoint);
//    painter.drawRect (rect);
}

void MRArticlePageDisplayer::drawRectangle(QPainter &painter, const MRAnnotation &annot)
{
//    fz_rect rect = mapFromOrigin (annot.getRect (),
//                                  scaleX,
//                                  scaleY,
//                                  rotation);

//    QRectF qrect(QPointF(rect.x0,rect.y0),
//                QPointF(rect.x1, rect.y1));
//    painter.begin (this);
//    QPen pen(Qt::red, 2);
//    painter.setPen (pen);
//    painter.setRenderHint (QPainter::Antialiasing);
//    painter.drawRect (qrect);
}


void MRArticlePageDisplayer::appendAnnotation(int type, const char* content)
{
//    MRAnnotation annotation;
//    annotation.setType (type);
//    fz_rect rect;
//    rect.x0 = startPoint.x ();
//    rect.y0 = startPoint.y ();
//    rect.x1 = endPoint.x ();
//    rect.y1 = endPoint.y ();
//    annotation.setRect (rect);
//    annotation.setContent (content);
//    annotations.append (annotation);
//    Q_ASSERT (page);
//    page->addAnnotation (type,
//                         rect,
//                         content);
}

void MRArticlePageDisplayer::appendAnnotation(int type, const fz_quad &quad, char *content)
{
//    MRAnnotation annotation;
//    annotation.setType (type);
//    fz_rect rect;
//    rect.x0 = quad.ul.x;
//    rect.y0 = quad.ul.y;
//    rect.x1 = quad.lr.x;
//    rect.y1 = quad.lr.y;
//    annotation.setRect (rect);
//    annotation.setContent (content);
//    annotations.append (annotation);
//    Q_ASSERT (page);
//    page->addAnnotation (type, rect,
//                         content);
}

void MRArticlePageDisplayer::appendAnnotation()
{
    std::shared_ptr<MRAnnotation> annot = MRAnnotationCreator::createAnnotation (d->annotFlag);
    Q_ASSERT (annot != nullptr );
    Q_ASSERT ( d != nullptr );
    fz_point start, end;
    memset (&start, 0, sizeof(fz_point));
    memset (&end, 0, sizeof(fz_point));
    start.x = d->mouseStartPoint.x ();
    start.y = d->mouseStartPoint.y ();
    end.x = d->mouseEndPoint.x ();
    end.y = d->mouseEndPoint.y ();
    mapToOrigin (start, d->scaleX, d->scaleY, d->rotation);
    mapToOrigin (end, d->scaleX, d->scaleY, d->rotation);
    annot->setStart (start);
    annot->setEnd (end);

    fz_rect rect;
    rect.x0 = d->mouseStartPoint.x ();
    rect.y0 = d->mouseStartPoint.y ();
    rect.x1 = d->mouseEndPoint.x ();
    rect.y1 = d->mouseEndPoint.y ();
    mapToOrigin (rect, d->scaleX, d->scaleY, d->rotation);
    annot->setRect (rect);
    Q_ASSERT (d->page != nullptr );
    d->page->addAnnotation (annot);
    d->annotations.append (annot);
}

void MRArticlePageDisplayer::appendAnnotation(const fz_quad &quad)
{
    std::shared_ptr<MRAnnotation> annot = MRAnnotationCreator::createAnnotation (d->annotFlag);
    fz_rect rect;
    rect.x0 = quad.ul.x;
    rect.y0 = quad.ul.y;
    rect.x1 = quad.lr.x;
    rect.y1 = quad.lr.y;
    mapToOrigin (rect, d->scaleX, d->scaleY, d->rotation);
    annot->setRect (rect);
    d->annotations.append (annot);
    Q_ASSERT (d->page != nullptr );
    d->page->addAnnotation (annot);
}

QPixmap &&MRArticlePageDisplayer::grabRectangle()
{
    QRect rect = calculateSelectionRect ();
    QPixmap p = this->grab(rect);
    emit selectionReady (d->pageIndex, p);
    d->ocr->addPendingPix (p);
    return std::move(p);
}

QSize MRArticlePageDisplayer::pageSize() const
{
    return d->pageSize;
}

void MRArticlePageDisplayer::handleCursorType(CURSOR cursor)
{
    MRCursor::setCursor (this, cursor);
}

void MRArticlePageDisplayer::setImage(const QImage &img)
{
    this->setPixmap (QPixmap::fromImage (img));
//    qDebug() << "my size" << size ();
    update ();
}

QString MRArticlePageDisplayer::getTextFromSelection()
{
    Q_ASSERT (d != nullptr );
    Q_ASSERT ( d->page != nullptr );

    QRectF rect = calculateSelectionRectF ();
    rect = mapToOrigin (rect, d->scaleX, d->scaleY, d->rotation);
    fz_quad quads[200];
    int num = 0;
    QString str = d->page->getSelection (rect, quads, num);
    for(int i=0; i<num; i++)
    {
        appendAnnotation (PDF_ANNOT_HIGHLIGHT, quads[i]);
    }
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

