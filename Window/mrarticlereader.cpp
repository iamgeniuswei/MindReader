#include "mrarticlereader.h"
#include "mrarticlecanvas.h"
#include "articledisplayercontroller.h"
#include <QSplitter>
#include "mrreadertoolbar.h"
#include "mrsinglepagedisplayer.h"
#include "mrseriespagedisplayer.h"
#include <QScrollArea>
#include <QScrollBar>
MRArticleReader::MRArticleReader(QWidget *parent) : UIWidget(parent)
{
//    layout = new QVBoxLayout(this);
//    layout->setMargin (0);
//    canvas = new MRArticleDisplayer(this);
//    controller = new ArticleDisplayerController(this);
//    layout->addWidget (canvas, 1);
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
			 this, &MRArticleReader::displayFirstPage);
	connect (controller, &ArticleDisplayerController::prevPageClicked,
			 this, &MRArticleReader::displayPrevPage);
	connect (controller, &ArticleDisplayerController::nextPageClicked,
			 this, &MRArticleReader::displayNextPage);
	connect (controller, &ArticleDisplayerController::lastPageClicked,
			 this, &MRArticleReader::displayLastPage);
//    connect (controller, &ArticleDisplayerController::zoomInClicked,
//             canvas, &MRArticleDisplayer::zoomInPage);
//    connect (controller, &ArticleDisplayerController::zoomOutClicked,
//             canvas, &MRArticleDisplayer::zoomOutPage);
//    connect (canvas, &MRArticleDisplayer::selectionReady,
//             this, &MRArticleReader::selectionReady);
//    connect (canvas, &MRArticleDisplayer::ADCIndexItemsReady,
//             controller, &ArticleDisplayerController::updateADCIndex);
//    connect (canvas, &MRArticleDisplayer::textReady,
//             note, &NoteDisplayer::addTextCard);
//    connect (this, &MRArticleReader::cursorType,
//             canvas, &MRArticleDisplayer::cursorType);
	connect (this, &MRArticleReader::selectionReady,
			 note, &NoteDisplayer::addPixmapCard);
//    connect (this, &MRArticleReader::textReady,
//             note, &NoteDisplayer::addTextCard);
	connect (toolBar, &MRReaderToolBar::backLibraryClicked,
			 this, &MRArticleReader::backToLibrary);
	connect (toolBar, &MRReaderToolBar::cursorType,
			 this, &MRArticleReader::cursorType);
//    connect (toolBar, &MRReaderToolBar::colorReady,
//             canvas, &MRArticleDisplayer::colorReady);
}

bool MRArticleReader::setArticle(std::shared_ptr<MRArticleMetaData> article)
{
	if(canvas)
	{
		article_ = article;
		note->setArticle (article);
		return canvas->setArticle (article);
	}
}

void MRArticleReader::resetArticle()
{
	if(canvas)
	{
//        canvas->resetArticle ();
//        article_.reset ();
	}
}

void MRArticleReader::displayFirstPage()
{
	Q_ASSERT(canvas != nullptr);
	Q_ASSERT(canvasContainer != nullptr);
	if (canvas)
		canvas->firstPage();
	if (canvasContainer)
		canvasContainer->verticalScrollBar()->setValue(canvas->yValueForPage());
}

void MRArticleReader::displayPrevPage()
{
	Q_ASSERT(canvas != nullptr);
	Q_ASSERT(canvasContainer != nullptr);
	if (canvas)
		canvas->prevPage();
	if (canvasContainer)
		canvasContainer->verticalScrollBar()->setValue(canvas->yValueForPage());
}

void MRArticleReader::displayNextPage()
{
	Q_ASSERT(canvas != nullptr);
	Q_ASSERT(canvasContainer != nullptr);
	if (canvas)
		canvas->nextPage();
	if (canvasContainer)
		canvasContainer->verticalScrollBar()->setValue(canvas->yValueForPage());
}

void MRArticleReader::displayLastPage()
{
	Q_ASSERT(canvas != nullptr);
	Q_ASSERT(canvasContainer != nullptr);
	if (canvas)
		canvas->lastPage();
	if (canvasContainer)
		canvasContainer->verticalScrollBar()->setValue(canvas->yValueForPage());
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
	//canvas = new MRSinglePageDisplayer(this);

	canvasContainer = new QScrollArea(this);
	canvasContainer->setAlignment(Qt::AlignCenter);
	canvasContainer->setWidgetResizable (true);
	canvas = new MRSeriesPageDisplayer(this);
	canvasContainer->setWidget (canvas);
	controller = new ArticleDisplayerController(this);
	layout->addWidget (canvasContainer, 1);
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
