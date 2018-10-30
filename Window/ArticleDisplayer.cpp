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

#include "ArticleDisplayer.h"
#include "PDFDocument.h"
#include "PDFPage.h"
#include <QLabel>
#include "ArticlePage.h"
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
ArticleDisplayer::ArticleDisplayer(QWidget *parent)
: QScrollArea(parent)
{
    initializeUI();
//    PDFDocument *pdf = new PDFDocument();
//    pdf->openDocument("D:/Article/56.pdf");

////    setWidget(container);
////    delete pdf;


////    setWidget(label);
//    render = new ArticlePageRender(this);
//    render->setPDFDocument (pdf);
    initializeSignals ();
//    setPDFDocument (pdf);
}

ArticleDisplayer::~ArticleDisplayer()
{
}

void ArticleDisplayer::initializeUI()
{
    setAlignment (Qt::AlignCenter);
//    setAlignment(Qt::AlignHCenter);
//    setWidgetResizable (true);
    setBackgroundRole(QPalette::Dark);
//    container = new QWidget(this);
    content = new ArticlePage(this);
//    layout = new QVBoxLayout(container);
//    layout->addWidget (content);
//    container->setLayout(layout);
//    setWidget (container);
    setWidget (content);
    qDebug() << verticalScrollBar ()->maximum ();
}

void ArticleDisplayer::setPDFDocument(const PDFDocument* doc)
{
    pdf = doc;
//    ArticlePage *label = new ArticlePage(this);
    PDFPage *page = pdf->page(0);
    content->setPDFPage (page);
//    label->resize (532, 648);
//    content->setPixmap(QPixmap::fromImage(page->renderPage(2, 2, 0)));

    render->requestPage (0, 1.0,1.0, 0.0);
//    label->setPDFPage (page);//
//    layout->addWidget (label);
//    content = label;
//    if(pdf->pageCount ()>0)
//    {
//        PDFPage *page = pdf->page(0);
//        content->setPDFPage(page);
//        content->setPixmap(QPixmap::fromImage(page->renderPage(1, 1, 0)));
//        layout->addWidget(content);
//        labels.append (content);
//        current = 0;
//    }
//    m_totalPages = pdf->pageCount ();
//    if(pdf->pageCount () <= 10)
//    {
//        for (int i = 0; i < pdf->pageCount (); i++)
//        {

////            label->setPDFPage(page);
////            label->setPixmap(QPixmap::fromImage(page->renderPage(1, 1, 0)));
////            layout->addWidget(label);
////            labels.append (label);
//        }

//    }
//    else
//    {
//        for (int i = 0; i < 10; i++)
//        {
//            ArticlePage *label = new ArticlePage(this);
//            PDFPage *page = pdf->page(i);
//            label->setPDFPage(page);
//            label->setPixmap(QPixmap::fromImage(page->renderPage(1, 1, 0)));
//            layout->addWidget(label);
//            labels.append (label);
//        }
//        for (int i = 10; i < pdf->pageCount (); i++)
//        {
//            ArticlePage *label = new ArticlePage(this);
//            PDFPage *page = pdf->page(i);
//            label->setPDFPage(page);
//            label->setPixmap(QPixmap::fromImage(page->renderPage(1, 1, 0)));
//            layout->addWidget(label);
//            labels.append (label);
//        }
//    }


//    setViewport(container);
//    qDebug() << label->size () << ":::" <<label->sizeHint ();
//     qDebug() << "area size" << this->width ()<<" "<<this->height ();
    //     verticalScrollBar ()->setMaximum (100*648);
}

void ArticleDisplayer::setArticle(std::shared_ptr<MRArticleMetaData> article)
{
    MRSetting set;
    set.initializeSetting ("config.ini");
//    std::string working_dir = QString::toStdString (set.getWorkDirectory ());
    std::string path;
    if(!article->relative_path ().empty ())
        path = set.getWorkDirectory ().toStdString () + "/" + article->relative_path () + "/" + article->title ();
    else
        path = set.getWorkDirectory ().toStdString () + "/" + article->title ();
    PDFDocument *pdf = new PDFDocument();
    pdf->openDocument(QString::fromStdString (path));

    render = new ArticlePageRender(this);
    connect (render, &ArticlePageRender::pageReady,
             this, &ArticleDisplayer::displayPage);
    render->setPDFDocument (pdf);
    setPDFDocument (pdf);

}

void ArticleDisplayer::wheelEvent(QWheelEvent *event)
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

void ArticleDisplayer::initializeSignals()
{

    connect(content, &ArticlePage::selectionReady,
            this, &ArticleDisplayer::selectionReady);
    connect(content, &ArticlePage::textReady,
            this, &ArticleDisplayer::textReady);
    connect (this, &ArticleDisplayer::cursorType,
             content, &ArticlePage::handleCursorType);
}

void ArticleDisplayer::displayFirstPage()
{
    int current = 0;
    render->requestPage (current, 1.0, 1.0, 0.0);
}

void ArticleDisplayer::displayPrevPage()
{
    int current = content->pageIndex ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    if(current > 0)
        render->requestPage (--current, scaleX, scaleY, 0.0);
}

void ArticleDisplayer::displayNextPage()
{
    int current = content->pageIndex ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    if(current < (pdf->pageCount ()-1))
        render->requestPage (++current, scaleX, scaleY, 0.0);
}

void ArticleDisplayer::displayLastPage()
{
    int current = pdf->pageCount ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    render->requestPage (current-1, scaleX, scaleY, 0.0);
}

void ArticleDisplayer::zoomInPage()
{
    int current = content->pageIndex ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    scaleX += 0.1;
    scaleY += 0.1;
    render->requestPage (current, scaleX, scaleY, 0.0);
}

void ArticleDisplayer::zoomOutPage()
{
    int current = content->pageIndex ();
    float scaleX = content->getScaleX ();
    float scaleY = content->getScaleY ();
    scaleX -= 0.1;
    scaleY -= 0.1;
    if(scaleX <= 0.2 || scaleY <= 0.2)
        return;
    render->requestPage (current, scaleX, scaleY, 0.0);
}

void ArticleDisplayer::displayPage(float scaleX, float scaleY, float rotation, int page, QImage img, PDFPage *src)
{
    if(content)
    {
        img.save ("D:\\34.png");
        content->setPixmap (QPixmap::fromImage (img));
        content->setImage (img);
//        content->setScaledContents (true);
        content->resize (content->sizeHint ());
        content->setCurrentPageIndex (page);
        content->setScaleX (scaleX);
        content->setScaleY (scaleY);
        content->setPDFPage (src);
        verticalScrollBar ()->setValue (0);
    }
    qDebug() <<content->size () << ":::" <<content->sizeHint ();
}

//void ArticleDisplayer::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);

//    if (0 == m_totalPages)
//    {
//       return;
//    }

//    // Find the first page that needs to be rendered
//    int page = 0;
//    int y = 0;

//    while (page < m_totalPages)
//    {
////        int height = pageSize(page).toSize().height();
//        int height = 648;
//        if (y + height >= event->rect().top())
//        {
//            break;
//        }
//        y += m_pageSpacing + height;
//        ++page;
//    }
//    y += m_pageSpacing;

//    // Actually render pages
//    while (y < event->rect().bottom() && page < m_totalPages)
//    {
////        QSizeF size = pageSize(page);
//        QSizeF size(532,648);
//        PDFPage *page = pdf->page(1);
////        content->setPDFPage(page);
//        QImage img = page->renderPage (1,1,0);
//        painter.fillRect((width() - img.width()) / 2, y, size.width(), size.height(), Qt::white);
//        painter.drawImage((width() - img.width()) / 2, y, img);
////        if (m_pageCache.contains(page))
////        {
////            const QImage &img = m_pageCache[page];
////            painter.fillRect((width() - img.width()) / 2, y, size.width(), size.height(), Qt::white);
////            painter.drawImage((width() - img.width()) / 2, y, img);
////            getPage();
////            emit updatePdfInfo(m_pageIndex, m_totalPages, m_zoom);
////        }
////        else
////        {
////            painter.fillRect((width() - size.width()) / 2, y, size.width(), size.height(), Qt::white);
////            painter.drawPixmap((size.width() - m_placeholderIcon.width()) / 2,
////                               (size.height() - m_placeholderIcon.height()) / 2, m_placeholderIcon);
////            m_PageRender->requestPage(page, m_screenResolution * m_zoom);
////        }
//        y += size.height() + m_pageSpacing;
//        ++page;
//    }
//}
