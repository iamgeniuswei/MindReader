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

#include "ArticlePage.h"
#include <QMouseEvent>
#include "PDFPage.h"
#include "PDFUtil.h"
#include <QDebug>
#include <QPainter>
#include <QPaintEngine>
#include "mupdf/pdf.h"
#include "mupdf/fitz.h"
#include <QKeyEvent>
ArticlePage::ArticlePage(QWidget *parent)
    :QLabel(parent)
{
    setScaledContents (true);
    setMouseTracking (true);
    grabKeyboard ();
//    setCursor (Qt::IBeamCursor);
}

ArticlePage::~ArticlePage()
{
}

void ArticlePage::setPDFPage(PDFPage* src)
{
    page = src;
//    img = this->pixmap ()->toImage ();
    fz_annot *annot = fz_first_annot (page->context (), page->page ());
    if(annot)
    {
        pdf_annot *pdf_an = (pdf_annot*)annot;
        qDebug() << annot;
        qDebug() << pdf_annot_contents (page->context (),
                                        pdf_an);    }


}

int ArticlePage::pageIndex() const
{
    return currentPageIndex;
}

void ArticlePage::setCurrentPageIndex(int index)
{
    currentPageIndex = index;
}





void ArticlePage::mousePressEvent(QMouseEvent* ev)
{
//    startPoint = ev->localPos();
    startPoint = ev->pos ();
    draw = true;
    qDebug() << startPoint;
    qDebug()  << this->cursor ();
}

void ArticlePage::mouseMoveEvent(QMouseEvent *event)
{
    endPoint = event->pos ();
    if(shift)
    {
        endPoint.setY (startPoint.y ());
    }
    update ();
}

void ArticlePage::mouseReleaseEvent(QMouseEvent* event)
{
    draw = false;
    if(cursor_ == LINE)
    {
        MRAnnotaion annotation;
        annotation.setType (MRAnnotaion::ANNOTATION::LINE);
        annotation.setStart (startPoint);
        annotation.setEnd (endPoint);
        annotations.append (annotation);
    }


//    QPointF point;
//    point = event->localPos ();

//    QPainter painter(this);
//    painter.drawEllipse (pressPoint.x (), pressPoint.y (), point.x ()-pressPoint.x (),point.y ()-pressPoint.y ());
//    endPoint = event->localPos ();
    endPoint = event->pos ();
//    if(this->cursor () == Qt::ArrowCursor)
//    {
//        QString str = highlightSelection ();
//        qDebug() << str;
////        str.replace ("\r", "");
////        qDebug() << str;
//        if(!str.isEmpty ())
//            emit textReady (currentPageIndex, str);
//    }
//    else if (this->cursor () == Qt::ArrowCursor)
//    {
//        int x = startPoint.x();
//        int y = startPoint.y ();
//        int width = endPoint.x () - startPoint.x ();
//        int height = endPoint.y () - startPoint.y ();
//        QPixmap p = this->grab(QRect(x, y, width, height));
//        emit selectionReady (currentPageIndex, p);
//    }

//    repaint ();
//    qDebug() << page->context ();
//    qDebug() << page->document ();
////    pdf_document * doc = pdf_document_from_fz_document (page->context (), page->document ());
//    pdf_document *doc = (pdf_document*)(page->document ());
////    pdf_page * pdfPage = pdf_page_from_fz_page(page->context (), page->page ());

//    pdf_page *pdfPage = pdf_load_page (page->context (),
//                             doc,
//                             currentPageIndex);

//    pdf_annot *annot = pdf_create_annot (page->context (),
//                                         pdfPage,
//                                         PDF_ANNOT_HIGHLIGHT);
//    pdf_add_annot_quad_point (page->context (),
//                              annot,
//                              quads_list.at (0));

//    pdf_set_annot_contents (page->context (),
//                            annot,
//                            "THIS is annotation");

//    pdf_save_document(page->context (), doc,
//                      "D:/Article/testan.pdf",NULL);


}

void ArticlePage::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent (event);

    if(cursor_ == LINE && draw)
    {
        drawLine ();
    }

    for(int i=0; i<annotations.size (); i++)
    {
        MRAnnotaion tmp = annotations.at (i);
        if(tmp.getType () == MRAnnotaion::ANNOTATION::LINE)
        {
            drawLine (tmp.getStart (), tmp.getEnd ());
        }

    }

//    if(draw)
//    {
//        QPainter painter(this);
//        for(int i=0; i<quads_list.size (); i++)
//        {
//            fz_quad quad = quads_list.at (i);
//            QRectF rect = QRectF(quad.ul.x, quad.ul.y, quad.lr.x - quad.ll.x, quad.lr.y - quad.ul.y);
//            rect = mapFromOrigin (rect, scaleX, scaleY, rotation);
//            painter.fillRect (rect,
//                              QColor(100,100,100,80));
//        }
//    }
//
//    QLineF line(10.0, 80.0, 90.0, 20.0);

//    QPainter painter(this);
//    painter.setPen (Qt::green);
////    painter.setBrush (QBrush(Qt::white));
//////
//////    QPainter painter(this);
////    QRect rect(0, 0, 532,658);
//////    painter.fillRect(0, 0, 532, 648, Qt::white);
////    painter.drawRect (0,0,532,658);
////    resize (532,648);

//    painter.drawLine(line);

}

void ArticlePage::keyPressEvent(QKeyEvent *event)
{

    if(event->modifiers () == Qt::ShiftModifier)
    {
        shift = true;
        qDebug() << "shift Pressed";
    }
}

void ArticlePage::keyReleaseEvent(QKeyEvent *event)
{
    Q_UNUSED (event);
    shift = false;
}

void ArticlePage::drawLine()
{
    QPainter painter(this);
    painter.begin (this);
    QPen pen(Qt::red, 2);
    painter.setPen (pen);
    painter.setRenderHint (QPainter::Antialiasing);
    painter.drawLine (startPoint, endPoint);
    painter.end ();
}

void ArticlePage::drawLine(QPoint start, QPoint end)
{
    QPainter painter(this);
    painter.begin (this);
    QPen pen(Qt::red, 2);
    painter.setPen (pen);
    painter.setRenderHint (QPainter::Antialiasing);
    painter.drawLine (start, end);
    painter.end ();
}

void ArticlePage::handleCursorType(CURSOR cursor)
{
    cursor_ = cursor;
    if(cursor_ == HAND)
        setCursor (Qt::OpenHandCursor);
    else if (cursor == LINE) {
        setCursor (Qt::CrossCursor);
    }
}

void ArticlePage::setImage(const QImage &img)
{
    this->setPixmap (QPixmap::fromImage (img));
    qDebug() << "my size" << size ();
    update ();
}

QString ArticlePage::highlightSelection()
{
    if (nullptr == page) {
        return QString();
    }

    QRectF rect = calculateSelectionRect ();
    rect = mapToOrigin (rect, scaleX, scaleY, rotation);
    fz_quad quads[200];
    int num = 0;
    QString str = page->getSelection (rect, quads, num);
    for(int i=0; i<num; i++)
    {
        quads_list << quads[i];
    }

    draw = true;
    return str;
}

QRectF ArticlePage::calculateSelectionRect()
{
    qreal x0 = 0, y0 = 0, x1 = 0, y1 = 0;
    if (endPoint != startPoint)
    {
        if (startPoint.x() > endPoint.x())
        {
            x0 = endPoint.x();
            x1 = startPoint.x();
        } else {
            x0 = startPoint.x();
            x1 = endPoint.x();
        }
        if (startPoint.y() > endPoint.y()) {
            y0 = endPoint.y();
            y1 = startPoint.y();
        } else {
            y0 = startPoint.y();
            y1 = endPoint.y();
        }
    }
    QRectF rect(x0, y0, x1 - x0, y1 - y0);
    return rect;
}


//TODO:重载了paintEvent事件处理函数后，QLabel的size出现了问题:
//1)自绘制区域没有得到空间，使用sizeHint（）得到解决，但是实际问题机理尚不明确。

//QSize ArticlePage::sizeHint() const
//{
//    return QSize(1200,1200);
//}

float ArticlePage::getScaleX() const
{
    return scaleX;
}

void ArticlePage::setScaleX(float value)
{
    scaleX = value;
}

float ArticlePage::getScaleY() const
{
    return scaleY;
}

void ArticlePage::setScaleY(float value)
{
    scaleY = value;
}

