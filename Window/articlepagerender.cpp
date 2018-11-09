#include "articlepagerender.h"
#include "mrpage.h"
#include "mrdocument.h"
#include <QImage>
#include <QDebug>
ArticlePageRender::ArticlePageRender(QObject *parent) : QThread(parent)
{

}

void ArticlePageRender::run()
{
    while (true) {
        try
        {
            int i = pendingIndex.wait_and_pop ();
            if(i == 0)
                continue;
            qDebug() << "i: " << i;
            this->pageIndex = i;
            std::shared_ptr<MRPage> page = doc->page (i);
            const QImage &img = page->renderPage (scaleX, scaleY, rotation);
            emit pageReady (scaleX, scaleY, rotation, i, img, page);
        }
        catch (std::exception &e)
        {
            qDebug() << e.what ();
        }
    }
//    if(doc == nullptr)
//        return;
//    for(int i=sIndex; i<=eIndex; i++)
//    {
//        qDebug() << "i: " << i;
//        this->pageIndex = i;
//        std::shared_ptr<MRPage> page = doc->page (i);
//        const QImage &img = page->renderPage (scaleX, scaleY, rotation);
//        emit pageReady (scaleX, scaleY, rotation, i, img, page);
//    }

}

void ArticlePageRender::requestPage(int page, float scaleX, float scaleY, float rotation)
{
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->rotation = rotation;
    this->pageIndex = page;
    start ();
}

void ArticlePageRender::requestPage(int sIndex, int eIndex, float scaleX, float scaleY, float rotation)
{
//    this->scaleX = scaleX;
//    this->scaleY = scaleY;
//    this->rotation = rotation;
//    this->sIndex = sIndex;
//    this->eIndex = eIndex;
//    start();
    for(int i=sIndex; i<=eIndex; i++)
        pendingIndex.push (i);
}

void ArticlePageRender::setPDFDocument(std::shared_ptr<MRDocument> document)
{
    doc = document;
}

void ArticlePageRender::retDocument()
{
    doc = nullptr;
}
