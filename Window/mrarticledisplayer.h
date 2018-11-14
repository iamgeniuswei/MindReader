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

#ifndef _MRARTICLEDISPLAYER_H
#define _MRARTICLEDISPLAYER_H

#include <QScrollArea>
#include <QWidget>
#include <QVBoxLayout>
#include "window_global.h"
#include <QLabel>
#include "mrarticlepagedisplayer.h"
#include "articlepagerender.h"
#include "mrwindowutility.h"
class MRDocument;
class MRPage;
class MRArticleMetaData;
class MRArticleLoader;
class QVBoxLayout;
class WINDOWSHARED_EXPORT MRArticleDisplayer : public QScrollArea
{
    Q_OBJECT
public:
    MRArticleDisplayer(QWidget *parent = nullptr);
    virtual ~MRArticleDisplayer();
    bool setArticle(std::shared_ptr<MRArticleMetaData> article);
protected:
    virtual void wheelEvent(QWheelEvent *event);

protected:
    virtual void loadUI();
    virtual void loadSignals();

signals:
    void selectionReady(int page, const QPixmap& pixmap);
    void textReady(int page, const QString& text);
    void cursorType(CURSOR cursor);
    void colorReady(const QColor& color);
    void ADCIndexItemsReady(const QStringList& items);
public slots:
    virtual void displayFirstPage();
    virtual void displayPrevPage();
    virtual void displayNextPage();
    virtual void displayLastPage();
    virtual void zoomInPage();
    virtual void zoomOutPage();
    virtual void displayPage(float scaleX,
                     float scaleY,
                     float rotation,
                     int index,
                     QImage img,
                     std::shared_ptr<MRPage> src);
    void resetArticle();
    void updatePageForm(PAGEFORM value);

private slots:
    virtual void handleDocReady(bool ret, std::shared_ptr<MRDocument> document);
    void handleScrollBarChanged(int value);

    protected:
//    QScrollArea *container = nullptr;
    QVBoxLayout *layout = nullptr;
    std::shared_ptr<MRDocument> doc = nullptr;
    MRArticlePageDisplayer *content = nullptr;
    QLabel *second = nullptr;
    QLabel *third = nullptr;
    QList<MRArticlePageDisplayer*> pages;
    QList<QPixmap> pixmaps;
    int current;
    int index;
    int m_totalPages;
    int m_pageSpacing = 6;
    ArticlePageRender *render = nullptr;
    PAGEFORM form = PAGEFORM::CONTINUOUS;
    MRArticleLoader *loader = nullptr;
    QWidget *container = nullptr;
    int MAX_PAGE_ON_DISPLAY = 10;
    int curIndexOnDisplay = 0;
};

#endif /* _MRARTICLEDISPLAYER_H */
