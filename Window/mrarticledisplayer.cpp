/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArticleDisplayer.cpp
 * Author: develop
 *
 * Created on October 11, 2018, 10:42 AM
 */

#include "mrarticledisplayer.h"
#include "mrdocument.h"
#include "mrpage.h"
#include <QLabel>
#include "mrarticlepagedisplayer.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QScrollBar>
#include <QWheelEvent>
#include <QPainter>
#include "articledisplayercontroller.h"
#include "mrarticlemetadata.h"
#include "mrsetting.h"
#include <QString>
#include "mupdf/pdf.h"
#include "mrarticleloader.h"
#include <QVBoxLayout>
MRArticleDisplayer::MRArticleDisplayer(QWidget *parent)
: QScrollArea(parent)
{
    loadUI();
    loadSignals ();
}

MRArticleDisplayer::~MRArticleDisplayer()
{
}

void MRArticleDisplayer::loadUI()
{
    setAlignment (Qt::AlignCenter);
    setBackgroundRole(QPalette::Dark);
    container = new QWidget(this);
    layout = new QVBoxLayout(container);
    layout->setSizeConstraint (QLayout::SetMinAndMaxSize);
    qDebug() << "layout default: " << layout->spacing () << " " << layout->margin ();

//    content = new MRArticlePageDisplayer(this);
//    setWidget (content);
}


bool MRArticleDisplayer::setArticle(std::shared_ptr<MRArticleMetaData> article)
{
//    doc = std::make_shared<MRDocument>();
//    if(doc->openDocument(QString::fromStdString (article->relative_path ())))
//    {
//        content->setDoc (doc);
//        content->requestPage (0, 1.0, 1.0, 0.0);
//        QStringList items;
//        QString count = QString::number (doc->pageCount ());
//        for(int i=0; i<doc->pageCount (); i++)
//        {
//            items << (QString::number (i) + "/" + count);
//        }
//        emit ADCIndexItemsReady (items);
//    }
//    else
//    {
//        return false;
//    }
    QString articlePath = QString::fromStdString (article->relative_path ());
    Q_ASSERT (loader != nullptr );
    loader->loadArticle (articlePath);
    return true;
}

void MRArticleDisplayer::wheelEvent(QWheelEvent *event)
{
    int height = verticalScrollBar ()->value ();
    if(event->angleDelta ().y () < 0)
    {

            height += 20;
    }else if(event->angleDelta ().y () > 0)
    {
        if(height < 20)
            height = 0;
        else {
            height -= 20;
        }
    }

    verticalScrollBar ()->setValue (height);

    if(height >= verticalScrollBar ()->maximum ())
    {
        displayNextPage ();

    }
    else if(height == 0)
    {
        displayPrevPage ();
    }

}

void MRArticleDisplayer::loadSignals()
{
//    connect(content, &MRArticlePageDisplayer::selectionReady,
//            this, &MRArticleDisplayer::selectionReady);
//    connect(content, &MRArticlePageDisplayer::textReady,
//            this, &MRArticleDisplayer::textReady);
//    connect (this, &MRArticleDisplayer::cursorType,
//             content, &MRArticlePageDisplayer::handleCursorType);
    loader = new MRArticleLoader(this);
    connect (loader, &MRArticleLoader::docReady,
             this, &MRArticleDisplayer::handleDocReady);
    connect (loader, &MRArticleLoader::indexReady,
             this, &MRArticleDisplayer::ADCIndexItemsReady);

    render = new ArticlePageRender(this);
    connect (render, &ArticlePageRender::pageReady,
             this, &MRArticleDisplayer::displayPage);
    connect (verticalScrollBar (), &QScrollBar::valueChanged,
             this, &MRArticleDisplayer::handleScrollBarChanged);
    render->start ();
}

void MRArticleDisplayer::displayFirstPage()
{
    Q_ASSERT (content);
    int current = 0;
    content->requestPage (current, 1.0, 1.0, 0.0);
}

void MRArticleDisplayer::displayPrevPage()
{
    Q_ASSERT (content );
    int current = content->pageIndex ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    if(current > 0)
        content->requestPage (--current, scaleX, scaleY, 0.0);
}

void MRArticleDisplayer::displayNextPage()
{
    Q_ASSERT (content );
    int current = content->pageIndex ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    if(current < (doc->pageCount ()-1))
        content->requestPage (++current, scaleX, scaleY, 0.0);
}

void MRArticleDisplayer::displayLastPage()
{
    Q_ASSERT (content );
    int current = doc->pageCount ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    content->requestPage (current-1, scaleX, scaleY, 0.0);
}

void MRArticleDisplayer::zoomInPage()
{
    Q_ASSERT (content );
    int current = content->pageIndex ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    scaleX += 0.1;
    scaleY += 0.1;
    content->requestPage (current, scaleX, scaleY, 0.0);
}

void MRArticleDisplayer::zoomOutPage()
{
    Q_ASSERT (content );
    int current = content->pageIndex ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    scaleX -= 0.1;
    scaleY -= 0.1;
    if(scaleX <= 0.2 || scaleY <= 0.2)
        return;
    content->requestPage (current, scaleX, scaleY, 0.0);
}

void MRArticleDisplayer::displayPage(float scaleX, float scaleY, float rotation, int index, QImage img, std::shared_ptr<MRPage> src)
{
//    if(content)
//    {
//        img.save ("D:\\34.png");
//        content->setPixmap (QPixmap::fromImage (img));
//        content->setImage (img);
////        content->setScaledContents (true);
//        content->resize (content->sizeHint ());
//        content->setCurrentPageIndex (page);
//        content->setScaleX (scaleX);
//        content->setScaleY (scaleY);
//        content->setPDFPage (src);
//        verticalScrollBar ()->setValue (0);
//    }
//    qDebug() <<content->size () << ":::" <<content->sizeHint ();
    MRArticlePageDisplayer *page = pages.at (index);
    Q_ASSERT (page);
    page->displayPage (scaleX, scaleY, rotation, index, img, src);
    qDebug() << "MAX_PAGE: " << MAX_PAGE_ON_DISPLAY;
//    QPixmap pixmap =QPixmap::fromImage (img);
//    pixmaps.append (pixmap);

}

void MRArticleDisplayer::resetArticle()
{
//    int ret;
//    render->exit (ret);
//    qDebug() << ret;
//    render->retDocument ();
//    if(doc != nullptr )
//        delete doc;
    doc = nullptr;
    int i = 0;
}

void MRArticleDisplayer::updatePageForm(PAGEFORM value)
{
    if(form == value )
        return;
    form = value;
}

void MRArticleDisplayer::handleDocReady(bool ret, std::shared_ptr<MRDocument> document)
{
    qDebug() << ret;
    doc = document;
    if(form == PAGEFORM::CONTINUOUS)
    {
        for(int i=0; i<doc->pageCount (); i++)
        {
            MRArticlePageDisplayer *page = new MRArticlePageDisplayer(container);
            page->setDoc (doc);
//            page->requestPage (i, 1.0, 1.0, 0.0);
            pages << page;
            layout->addWidget (page);
//            setWidget (page);
        }
        container->setLayout (layout);
        qDebug() << container->size () << container->sizeHint ();
        setWidget (container);
    }

    else if(form == PAGEFORM::SINGLE)
    {

    }
    render->setPDFDocument (doc);
    render->requestPage (0, 9, 1.0, 1.0, 0.0);
}

void MRArticleDisplayer::handleScrollBarChanged(int value)
{
    qDebug() << "bar value: " << value;
    int total = 9;
    for(int i=0; i<=curIndexOnDisplay; i++)
    {
        MRArticlePageDisplayer *page = pages.at (i);
        total += page->pageSize ().height ();
        total += 6;
    }
    qDebug() << "total: " << total;
    if((value - total) >= 0)
    {
        curIndexOnDisplay ++;
        verticalScrollBar ()->setValue (total);
        qDebug() << "curIndexOnDisplay: " << curIndexOnDisplay;
        if(curIndexOnDisplay >= 2)
        {
            MRArticlePageDisplayer *page = pages.at(curIndexOnDisplay-2);
            page->clear ();
            page = pages.at (MAX_PAGE_ON_DISPLAY);
            render->requestPage (MAX_PAGE_ON_DISPLAY,
                                 MAX_PAGE_ON_DISPLAY+1,
                                 1.0,
                                 1.0,
                                 0.0);
            MAX_PAGE_ON_DISPLAY+=2;

        }
    }
}
