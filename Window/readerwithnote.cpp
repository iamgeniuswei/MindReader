#include "readerwithnote.h"

ReaderWithNote::ReaderWithNote(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    reader = new ArticleReader(this);
    note = new NoteDisplayer(this);
    layout->addWidget (reader, 1);
    layout->addWidget (note);
    setLayout (layout);
    initializeSignal ();
}

void ReaderWithNote::initializeSignal()
{
    connect (reader, &ArticleReader::selectionReady,
             note, &NoteDisplayer::addPixmapCard);
    connect (reader, &ArticleReader::textReady,
             note, &NoteDisplayer::addTextCard);
}
