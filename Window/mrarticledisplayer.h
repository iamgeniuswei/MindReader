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
#include "mrarticlepagedisplayer.h"
#include "articlepagerender.h"
#include "mrwindowutility.h"
class MRDocument;
class MRPage;
class MRArticleMetaData;
class WINDOWSHARED_EXPORT MRArticleDisplayer : public QScrollArea
{
    Q_OBJECT
public:
    MRArticleDisplayer(QWidget *parent = nullptr);
    virtual ~MRArticleDisplayer();
    bool setArticle(std::shared_ptr<MRArticleMetaData> article);
protected:
    virtual void wheelEvent(QWheelEvent *event);
//    virtual void paintEvent(QPaintEvent * event);

protected:
    void loadUI();
    void loadSignals();

signals:
    void selectionReady(int page, const QPixmap& pixmap);
    void textReady(int page, const QString& text);
    void cursorType(CURSOR cursor);
    void ADCIndexItemsReady(const QStringList& items);
public slots:
    void displayFirstPage();
    void displayPrevPage();
    void displayNextPage();
    void displayLastPage();
    void zoomInPage();
    void zoomOutPage();
//    void displayPage(float scaleX, float scaleY, float rotation, int page, QImage img, MRPage *src);
    void resetArticle();


private:
    QScrollArea *container = nullptr;
    QVBoxLayout *layout = nullptr;
    std::shared_ptr<MRDocument> doc = nullptr;
    MRArticlePageDisplayer *content = nullptr;
    QLabel *second = nullptr;
    QLabel *third = nullptr;
    QList<MRArticlePageDisplayer*> labels;
    int current;
    int index;
    int m_totalPages;
    int m_pageSpacing = 6;
    ArticlePageRender *render = nullptr;
};

#endif /* _ARTICLEDISPLAYER_H */
