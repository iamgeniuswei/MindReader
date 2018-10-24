#include "notecard.h"
#include "ui_notecard.h"
#include <QMouseEvent>
NoteCard::NoteCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoteCard)
{
    ui->setupUi(this);
//    ui->content->setGeometry(QRect(328, 240, 329, 27*10));  //四倍行距

    ui->content->setWordWrap(true);
    ui->content->setAlignment(Qt::AlignTop);
    ui->content->setScaledContents (true);
}

NoteCard::~NoteCard()
{
    delete ui;
}

void NoteCard::setTitle(const QString &title)
{
    ui->title->setText (title);
    ui->title->adjustSize ();
}

void NoteCard::setText(const QString &text)
{
    ui->content->setText (text);
    ui->content->adjustSize ();
}

void NoteCard::setIndex(int index)
{
    ui->index->setText (QString::number (index, 10));
}

void NoteCard::setPixmap(const QPixmap &pixmap)
{
//    ui->content->setPixmap (pixmap);
}

void NoteCard::mousePressEvent(QMouseEvent *event)
{
    startPoint = this->pos ();
    QPoint mousePos = event->globalPos ();
    distance = mousePos - startPoint;

}

void NoteCard::mouseReleaseEvent(QMouseEvent *event)
{

}

void NoteCard::mouseMoveEvent(QMouseEvent *event)
{
    endPoint = event->globalPos ();
    move (endPoint - distance);
}
