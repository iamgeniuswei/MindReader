#include "articlepagerender.h"
#include "PDFPage.h"
#include "PDFDocument.h"
#include <QImage>
ArticlePageRender::ArticlePageRender(QObject *parent) : QThread(parent)
{

}

void ArticlePageRender::run()
{
    if(doc == nullptr)
        return;
    PDFPage *page = doc->page (pageIndex);
    const QImage &img = page->renderPage (scaleX, scaleY, rotation);
    emit pageReady (scaleX, scaleY, rotation, pageIndex, img);
}

void ArticlePageRender::requestPage(int page, float scaleX, float scaleY, float rotaion)
{
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->rotation = rotaion;
    this->pageIndex = page;
    start ();
}

void ArticlePageRender::setPDFDocument(PDFDocument *document)
{
    doc = document;
}
