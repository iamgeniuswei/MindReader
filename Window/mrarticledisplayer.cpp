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
    content = new MRArticlePageDisplayer(this);
    setWidget (content);
}


bool MRArticleDisplayer::setArticle(std::shared_ptr<MRArticleMetaData> article)
{
    doc = std::make_shared<MRDocument>();
    if(doc->openDocument(QString::fromStdString (article->relative_path ())))
    {
        content->setDoc (doc);
        content->requestPage (0, 1.0, 1.0, 0.0);
        QStringList items;
        QString count = QString::number (doc->pageCount ());
        for(int i=0; i<doc->pageCount (); i++)
        {
            items << (QString::number (i) + "/" + count);
        }
        emit ADCIndexItemsReady (items);
    }
    else
    {
        return false;
    }
    return true;
}

void MRArticleDisplayer::wheelEvent(QWheelEvent *event)
{
    int height = verticalScrollBar ()->value ();
    qDebug() << event->angleDelta ();
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

    connect(content, &MRArticlePageDisplayer::selectionReady,
            this, &MRArticleDisplayer::selectionReady);
    connect(content, &MRArticlePageDisplayer::textReady,
            this, &MRArticleDisplayer::textReady);
    connect (this, &MRArticleDisplayer::cursorType,
             content, &MRArticlePageDisplayer::handleCursorType);
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

//void MRArticleDisplayer::displayPage(float scaleX, float scaleY, float rotation, int page, QImage img, MRPage *src)
//{
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
//}

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
