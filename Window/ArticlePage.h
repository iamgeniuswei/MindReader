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
//#include "mupdf/fitz.h"
//#include "mupdf/pdf/annot.h"
#include "mupdf/fitz.h"
#include "mrwindowutility.h"
#include "mrannotaion.h"
class PDFPage;
class WINDOWSHARED_EXPORT ArticlePage : public QLabel
{
    enum STATE{READ, SELECTION};
    Q_OBJECT
public:
    ArticlePage(QWidget *parent = nullptr);
    ~ArticlePage();
    void setPDFPage(PDFPage *src);
    int pageIndex() const;
    void setCurrentPageIndex(int index);
protected:
    virtual void mousePressEvent(QMouseEvent* ev) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    void drawLine();
    void drawLine(QPoint start, QPoint end);

public slots:
    void handleCursorType(CURSOR cursor );

signals:
    void selectionReady(int page, const QPixmap& pixmap);
    void textReady(int page, const QString& text);

public:
//    virtual QSize sizeHint() const override;
    void setImage(const QImage &img);
    QString highlightSelection();
    QRectF calculateSelectionRect();


        
    float getScaleX() const;
    void setScaleX(float value);

    float getScaleY() const;
    void setScaleY(float value);

private:
    QPoint startPoint;
    QPoint endPoint;
    PDFPage *page = nullptr;
    QImage img;
    bool first = true;
    int currentPageIndex = 0;
    float scaleX = 1.0;
    float scaleY = 1.0;
    float rotation = 0.0;
    bool draw = false;
    QList<fz_quad> quads_list;
    QList<MRAnnotaion> annotations;
    CURSOR cursor_;
    bool shift = false;
};

#endif /* _ARTICLEPAGE_H */
