/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QImageTextItem.cpp
 * Author: develop
 * 
 * Created on October 16, 2018, 8:20 AM
 */

#include "QImageTextItem.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QPixmap>
QImageTextItem::QImageTextItem(QGraphicsItem *parent)
    :QGraphicsItem(parent)
{
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    initUI();
}

//QImageTextItem::QImageTextItem(const QImageTextItem& orig)
//{
//
//}

QImageTextItem::~QImageTextItem()
{
}

void QImageTextItem::initUI()
{
    pixmap = new QGraphicsPixmapItem(this);
    text = new QGraphicsTextItem(this);
//    pixmap->setPos(boundingRect().left(), boundingRect().top());
//    text->setPos(pixmap->boundingRect().left(), pixmap->boundingRect().bottom());
}

QRectF QImageTextItem::boundingRect() const
{
    return QRectF(0, 0, 120, 120);
}

void QImageTextItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    
}

void QImageTextItem::setImage(const QString& path, qreal scale)
{    
    if(pixmap)
    {
        QPixmap tmp(path);
        pixmap->setPixmap(tmp);
        pixmap->setScale(scale);
        text->setPos(pixmap->boundingRect().left(), pixmap->boundingRect().bottom()*scale);
    }
}

void QImageTextItem::setText(const QString& src_text)
{
    if(text)
    {
        text->setPlainText(src_text);        
    }
}


