#include "notedisplayer.h"
#include <QDebug>
#include "mrnotedata.h"
NoteDisplayer::NoteDisplayer(QWidget *parent) : QScrollArea (parent)
{
    initializeUI ();
    initializeSignal ();

//    addCard (1, "dsafasfasfaf", "dsfafas");
//    addCard (100, "dsafafasfas\ndsafasfdasf", "dsfasfasf");

}

void NoteDisplayer::setArticle(std::shared_ptr<MRArticleMetaData> article_)
{
    article = article_;
}

void NoteDisplayer::addCard(int index, const QString &text, const QString &title)
{
    if(container && layout)
    {
        NoteCard *card = new (std::nothrow) NoteCard(this);
        card->setArticle (article);
        if(card == nullptr)
        {
            qDebug() << "error!";
            return;
        }
        card->setIndex (index);
        card->setTitle (title);
        card->setText (text);
        layout->addWidget (card);
    }
//    show();
    setWidget (container);
}

void NoteDisplayer::addTextCard(int index, const QString &text)
{
    if(container && layout)
    {
        NoteCard *card = new (std::nothrow) NoteCard(this);
        card->setArticle (article);
        if(card == nullptr)
        {
            qDebug() << "error!";
            return;
        }
        card->setIndex (index);
        card->setText (text);
        layout->addWidget (card);
    }
//    show();
//    setWidget (container);
}

void NoteDisplayer::addPixmapCard(int index, const QPixmap &pixmap)
{
    if(container && layout)
    {
        NoteCard *card = new (std::nothrow) NoteCard(this);
        if(card == nullptr)
        {
            qDebug() << "error!";
            return;
        }
        card->setIndex (index);
        card->setPixmap (pixmap);
        layout->addWidget (card);
    }
//    show();
    setWidget (container);
}

void NoteDisplayer::initializeUI()
{
    setMinimumWidth (340);
//    setWidgetResizable (true);
    container = new QWidget(this);
    layout = new QVBoxLayout(container);
    layout->setSizeConstraint (QLayout::SetMinAndMaxSize);
    container->setLayout (layout);
    setWidget (container);

}

void NoteDisplayer::initializeSignal()
{

}
