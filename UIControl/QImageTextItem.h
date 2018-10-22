/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QImageTextItem.h
 * Author: develop
 *
 * Created on October 16, 2018, 8:20 AM
 */

#ifndef QIMAGETEXTITEM_H
#define QIMAGETEXTITEM_H
#include <QGraphicsItem>
class QGraphicsPixmapItem;
class QGraphicsTextItem;
class QImageTextItem : public QGraphicsItem
{
public:
    QImageTextItem(QGraphicsItem *parent = nullptr);
//    QImageTextItem(const QImageTextItem& orig);
    virtual ~QImageTextItem();
    
public:
    void setImage(const QString& path, qreal scale = 1.0);
    void setText(const QString& src_text);
    QRectF boundingRect() const override;
protected:
    void initUI();
    
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;


private:
    QGraphicsPixmapItem *pixmap = nullptr;
    QGraphicsTextItem *text = nullptr;
};

#endif /* QIMAGETEXTITEM_H */

