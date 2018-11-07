#include "mrarticlereader.h"
#include "MRArticleDisplayer.h"
#include "articledisplayercontroller.h"
#include <QSplitter>
#include "mrreadertoolbar.h"
MRArticleReader::MRArticleReader(QWidget *parent) : UIWidget(parent)
{
//    layout = new QVBoxLayout(this);
//    layout->setMargin (0);
//    displayer = new MRArticleDisplayer(this);
//    controller = new ArticleDisplayerController(this);
//    layout->addWidget (displayer, 1);
//    layout->addWidget (controller, 0, Qt::AlignBottom);
//    setLayout (layout);
//    horizontalLayout = new QHBoxLayout(this);
//    noteDisplayer = new NoteDisplayer(this);
//    horizontalLayout->addLayout (layout, 1);
//    horizontalLayout->addWidget (noteDisplayer);
//    setLayout (horizontalLayout);
    loadUI ();
    initializeSignals ();
}

void MRArticleReader::initializeSignals()
{
    connect (controller, &ArticleDisplayerController::firstPageClicked,
             displayer, &MRArticleDisplayer::displayFirstPage);
    connect (controller, &ArticleDisplayerController::prevPageClicked,
             displayer, &MRArticleDisplayer::displayPrevPage);
    connect (controller, &ArticleDisplayerController::nextPageClicked,
             displayer, &MRArticleDisplayer::displayNextPage);
    connect (controller, &ArticleDisplayerController::lastPageClicked,
             displayer, &MRArticleDisplayer::displayLastPage);
    connect (controller, &ArticleDisplayerController::zoomInClicked,
             displayer, &MRArticleDisplayer::zoomInPage);
    connect (controller, &ArticleDisplayerController::zoomOutClicked,
             displayer, &MRArticleDisplayer::zoomOutPage);
    connect (displayer, &MRArticleDisplayer::selectionReady,
             this, &MRArticleReader::selectionReady);
    connect (displayer, &MRArticleDisplayer::textReady,
             this, &MRArticleReader::textReady);
    connect (this, &MRArticleReader::cursorType,
             displayer, &MRArticleDisplayer::cursorType);
    connect (this, &MRArticleReader::selectionReady,
             note, &NoteDisplayer::addPixmapCard);
    connect (this, &MRArticleReader::textReady,
             note, &NoteDisplayer::addTextCard);
    connect (toolBar, &MRReaderToolBar::backLibraryClicked,
             this, &MRArticleReader::backToLibrary);
    connect (toolBar, &MRReaderToolBar::cursorType,
             this, &MRArticleReader::cursorType);
}

bool MRArticleReader::setArticle(std::shared_ptr<MRArticleMetaData> article)
{
    if(displayer)
    {
        article_ = article;
        return displayer->setArticle (article);
    }
}

void MRArticleReader::resetArticle()
{
    if(displayer)
    {
        displayer->resetArticle ();
        article_.reset ();
    }
}

std::shared_ptr<MRArticleMetaData> MRArticleReader::article() const
{
    return article_;
}

void MRArticleReader::loadUI()
{
    readerContainer = new QWidget(this);
    layout = new QVBoxLayout(readerContainer);
    layout->setMargin (0);
    displayer = new MRArticleDisplayer(this);
    controller = new ArticleDisplayerController(this);
    layout->addWidget (displayer, 1);
    layout->addWidget (controller, 0, Qt::AlignBottom);
    readerContainer->setLayout (layout);
    mainLayout = new QVBoxLayout(this);
    toolBar = new MRReaderToolBar(this);
    mainLayout->addWidget (toolBar, 0, Qt::AlignTop);
    note = new NoteDisplayer(this);
    splitter = new QSplitter(this);
    splitter->addWidget (readerContainer);
    splitter->addWidget (note);
    mainLayout->addWidget (splitter,1);
    setLayout (mainLayout);
}
