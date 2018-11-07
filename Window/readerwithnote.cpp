#include "readerwithnote.h"

ReaderWithNote::ReaderWithNote(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    reader = new MRArticleReader(this);
    note = new NoteDisplayer(this);
    layout->addWidget (reader, 1);
    layout->addWidget (note);
    setLayout (layout);
    initializeSignal ();
}

void ReaderWithNote::initializeSignal()
{
    connect (reader, &MRArticleReader::selectionReady,
             note, &NoteDisplayer::addPixmapCard);
    connect (reader, &MRArticleReader::textReady,
             note, &NoteDisplayer::addTextCard);
}
