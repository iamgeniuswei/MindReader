#include "articlepagerender.h"
#include "mrpage.h"
#include "mrdocument.h"
#include <QImage>

ArticlePageRender::ArticlePageRender(QObject *parent) : QThread(parent)
{

}

void ArticlePageRender::run()
{
    if(doc == nullptr)
        return;
    std::shared_ptr<MRPage> page = doc->page (pageIndex);
    const QImage &img = page->renderPage (scaleX, scaleY, rotation);
    emit pageReady (scaleX, scaleY, rotation, pageIndex, img, page);
}

void ArticlePageRender::requestPage(int page, float scaleX, float scaleY, float rotaion)
{
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->rotation = rotaion;
    this->pageIndex = page;
    start ();
}

void ArticlePageRender::setPDFDocument(std::shared_ptr<MRDocument> document)
{
    doc = document;
}

void ArticlePageRender::retDocument()
{
    doc = nullptr;
}
