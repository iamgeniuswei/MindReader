/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ArticleDisplayer.h
 * Author: develop
 *
 * Created on October 11, 2018, 10:42 AM
 */

#ifndef _ARTICLEDISPLAYER_H
#define _ARTICLEDISPLAYER_H

#include <QScrollArea>
#include <QWidget>
#include <QVBoxLayout>
#include "window_global.h"
#include <QLabel>
#include "ArticlePage.h"
#include "articlepagerender.h"
class PDFDocument;
class PDFPage;
class WINDOWSHARED_EXPORT ArticleDisplayer : public QScrollArea
{
    Q_OBJECT
public:
    ArticleDisplayer(QWidget *parent = nullptr);
    virtual ~ArticleDisplayer();
    void setPDFDocument(const PDFDocument *doc);

protected:
    virtual void wheelEvent(QWheelEvent *event);
//    virtual void paintEvent(QPaintEvent * event);

protected:
    void initializeSignals();

signals:
    void selectionReady(int page, const QPixmap& pixmap);
    void textReady(int page, const QString& text);
public slots:
    void displayFirstPage();
    void displayPrevPage();
    void displayNextPage();
    void displayLastPage();
    void zoomInPage();
    void zoomOutPage();
    void displayPage(float scaleX, float scaleY, float rotation, int page, QImage img, PDFPage *src);


private:
    void initializeUI();
    QScrollArea *container = nullptr;
    QVBoxLayout *layout = nullptr;
    const PDFDocument *pdf = nullptr;
    ArticlePage *content = nullptr;
    QLabel *second = nullptr;
    QLabel *third = nullptr;
    QList<ArticlePage*> labels;
    int current;
    int index;
    int m_totalPages;
    int m_pageSpacing = 6;
    ArticlePageRender *render = nullptr;
};

#endif /* _ARTICLEDISPLAYER_H */
