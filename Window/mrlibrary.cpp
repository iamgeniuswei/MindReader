#include "mrlibrary.h"

MRLibrary::MRLibrary(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    toolBar = new MRLibraryToolBar(this);
    shelf = new ArticleShelf(this);
    layout->addWidget (toolBar, 0, Qt::AlignTop);
    layout->addWidget (shelf, 1);
    setLayout (layout);
    connect (shelf, &ArticleShelf::articleClicked,
             this, &MRLibrary::articleClicked);
}
