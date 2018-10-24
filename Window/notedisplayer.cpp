#include "notedisplayer.h"

NoteDisplayer::NoteDisplayer(QWidget *parent) : QGraphicsView(parent)
{

    scene = new QGraphicsScene(this);
    NoteCard *c1 = new NoteCard(this);
    NoteCard *c2 = new NoteCard(this);
    scene->addWidget (c1);
    scene->addWidget (c2);
    setScene (scene);
}
