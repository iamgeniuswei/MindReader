#include "articlereader.h"
#include "ArticleDisplayer.h"
#include "articledisplayercontroller.h"
ArticleReader::ArticleReader(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    displayer = new ArticleDisplayer(this);
    controller = new ArticleDisplayerController(this);
    layout->addWidget (displayer, 1);
    layout->addWidget (controller, 0, Qt::AlignBottom);
    setLayout (layout);
//    horizontalLayout = new QHBoxLayout(this);
//    noteDisplayer = new NoteDisplayer(this);
//    horizontalLayout->addLayout (layout, 1);
//    horizontalLayout->addWidget (noteDisplayer);
//    setLayout (horizontalLayout);
    initializeSignals ();
}

void ArticleReader::initializeSignals()
{
    connect (controller, &ArticleDisplayerController::firstPageClicked,
             displayer, &ArticleDisplayer::displayFirstPage);
    connect (controller, &ArticleDisplayerController::prevPageClicked,
             displayer, &ArticleDisplayer::displayPrevPage);
    connect (controller, &ArticleDisplayerController::nextPageClicked,
             displayer, &ArticleDisplayer::displayNextPage);
    connect (controller, &ArticleDisplayerController::lastPageClicked,
             displayer, &ArticleDisplayer::displayLastPage);
    connect (controller, &ArticleDisplayerController::zoomInClicked,
             displayer, &ArticleDisplayer::zoomInPage);
    connect (controller, &ArticleDisplayerController::zoomOutClicked,
             displayer, &ArticleDisplayer::zoomOutPage);
    connect (displayer, &ArticleDisplayer::selectionReady,
             this, &ArticleReader::selectionReady);
    connect (displayer, &ArticleDisplayer::textReady,
             this, &ArticleReader::textReady);
}
