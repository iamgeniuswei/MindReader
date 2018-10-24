#include "notecard.h"
#include "ui_notecard.h"

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
