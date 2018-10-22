/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArticlePage.h
 * Author: develop
 *
 * Created on October 12, 2018, 8:15 AM
 */

#ifndef _ARTICLEPAGE_H
#define _ARTICLEPAGE_H

#include <QLabel>
#include "window_global.h"
class PDFPage;
class WINDOWSHARED_EXPORT ArticlePage : public QLabel
{
    Q_OBJECT
public:
    ArticlePage(QWidget *parent = nullptr);
    ~ArticlePage();
    void setPDFPage(PDFPage *src);
    int pageIndex() const;
    void setCurrentPageIndex(int index);
protected:
    virtual void mousePressEvent(QMouseEvent* ev) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;
public:
    virtual QSize sizeHint() const override;


        
    float getScaleX() const;
    void setScaleX(float value);

    float getScaleY() const;
    void setScaleY(float value);

private:
    QPointF pressPoint;
    PDFPage *page = nullptr;
    QImage img;
    bool first = true;
    int currentPageIndex = 0;
    float scaleX = 1.0;
    float scaleY = 1.0;
    float rotation = 0.0;
};

#endif /* _ARTICLEPAGE_H */
