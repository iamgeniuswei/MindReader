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
ArticlePage::ArticlePage(QWidget *parent)
    :QLabel(parent)
{

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
    pressPoint = ev->localPos();
}

void ArticlePage::mouseReleaseEvent(QMouseEvent* event)
{
    QPointF point;
    point = event->localPos ();

    QPainter painter(this);
    painter.drawEllipse (pressPoint.x (), pressPoint.y (), point.x ()-pressPoint.x (),point.y ()-pressPoint.y ());

//    QPointF point;
//    float x0, y0, x1, y1;

//    if (nullptr == page) {
//        return;
//    }

//    point = event->localPos();
//    if (point != pressPoint) {
//        if (pressPoint.x() > point.x()) {
//            x0 = point.x();
//            x1 = pressPoint.x();
//        } else {
//            x0 = pressPoint.x();
//            x1 = point.x();
//        }
//        if (pressPoint.y() > point.y()) {
//            y0 = point.y();
//            y1 = pressPoint.y();
//        } else {
//            y0 = pressPoint.y();
//            y1 = point.y();
//        }
//        QRectF rect(x0, y0, x1 - x0, y1 - y0);
//        rect = mapToOrigin(rect, 1, 1, 0);
//        qDebug() << page->text(rect);
    //    }
}

void ArticlePage::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent (event);
//
    QLineF line(10.0, 80.0, 90.0, 20.0);

    QPainter painter(this);
    painter.setPen (Qt::green);
//    painter.setBrush (QBrush(Qt::white));
////
////    QPainter painter(this);
//    QRect rect(0, 0, 532,658);
////    painter.fillRect(0, 0, 532, 648, Qt::white);
//    painter.drawRect (0,0,532,658);
//    resize (532,648);

    painter.drawLine(line);

}


//TODO:重载了paintEvent事件处理函数后，QLabel的size出现了问题:
//1)自绘制区域没有得到空间，使用sizeHint（）得到解决，但是实际问题机理尚不明确。

QSize ArticlePage::sizeHint() const
{
    return QSize(1200,1200);
}

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

