#include "mrarticlereader.h"

MRArticleReader::MRArticleReader(QWidget *parent) : QWidget(parent)
{
    initializeUI ();
    initializeSignal ();
}

void MRArticleReader::initializeUI()
{
    mainLayout = new QVBoxLayout(this);
    toolBar = new MRReaderToolBar(this);
    mainLayout->addWidget (toolBar, 0, Qt::AlignTop);
    subLayout = new QHBoxLayout;
    reader = new ArticleReader(this);
    note = new NoteDisplayer(this);
    note->setArticle (reader->article ());
    subLayout->addWidget (reader, 1);
    subLayout->addWidget (note);
    mainLayout->addLayout (subLayout,1);
    setLayout (mainLayout);
}

void MRArticleReader::initializeSignal()
{
    connect (reader, &ArticleReader::selectionReady,
             note, &NoteDisplayer::addPixmapCard);
    connect (reader, &ArticleReader::textReady,
             note, &NoteDisplayer::addTextCard);
    connect (toolBar, &MRReaderToolBar::backLibraryClicked,
             this, &MRArticleReader::backToLibrary);
    connect (toolBar, &MRReaderToolBar::cursorType,
             reader, &ArticleReader::cursorType);

}

void MRArticleReader::setArticle(std::shared_ptr<MRArticleMetaData> article)
{
    if(reader)
    {
        reader->setArticle (article);
        note->setArticle (article);
    }
}

