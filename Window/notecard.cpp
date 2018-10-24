#include "notecard.h"
#include "ui_notecard.h"
#include <QMouseEvent>
NoteCard::NoteCard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NoteCard)
{
    ui->setupUi(this);
}

NoteCard::~NoteCard()
{
    delete ui;
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
