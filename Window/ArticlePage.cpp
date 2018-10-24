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
ArticlePage::ArticlePage(QWidget *parent)
    :QLabel(parent)
{
    setScaledContents (true);
    setCursor (Qt::IBeamCursor);
}

ArticlePage::~ArticlePage()
{
}

void ArticlePage::setPDFPage(PDFPage* src)
{
    page = src;
//    img = this->pixmap ()->toImage ();

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
    startPoint = ev->localPos();
    qDebug() << startPoint;
    qDebug()  << this->cursor ();
}

void ArticlePage::mouseReleaseEvent(QMouseEvent* event)
{
//    QPointF point;
//    point = event->localPos ();

//    QPainter painter(this);
//    painter.drawEllipse (pressPoint.x (), pressPoint.y (), point.x ()-pressPoint.x (),point.y ()-pressPoint.y ());
    endPoint = event->localPos ();
    if(this->cursor () == Qt::IBeamCursor)
    {
        highlightSelection ();
    }

    repaint ();
}

void ArticlePage::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent (event);
    if(draw)
    {
        QPainter painter(this);
        for(int i=0; i<quads_list.size (); i++)
        {
            fz_quad quad = quads_list.at (i);
            QRectF rect = QRectF(quad.ul.x, quad.ul.y, quad.lr.x - quad.ll.x, quad.lr.y - quad.ul.y);
            rect = mapFromOrigin (rect, scaleX, scaleY, rotation);
            painter.fillRect (rect,
                              QColor(100,100,100,80));
        }
    }
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

void ArticlePage::setImage(const QImage &img)
{
    this->setPixmap (QPixmap::fromImage (img));
    qDebug() << "my size" << size ();
    update ();
}

void ArticlePage::highlightSelection()
{
    if (nullptr == page) {
        return;
    }

    QRectF rect = calculateSelectionRect ();
    rect = mapToOrigin (rect, scaleX, scaleY, rotation);
    fz_quad quads[200];
    int num = 0;
    qDebug() << page->getSelection (rect, quads, num);
    for(int i=0; i<num; i++)
    {
        quads_list << quads[i];
    }

    draw = true;
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

