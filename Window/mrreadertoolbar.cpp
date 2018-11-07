#include "mrreadertoolbar.h"
#include "ui_mrreadertoolbar.h"
#include <QDebug>
MRReaderToolBar::MRReaderToolBar(QWidget *parent) :
    UIWidget(parent),
    ui(new Ui::MRReaderToolBar)
{
    ui->setupUi(this);
    ui->library->setObjectName ("toolButton");
    ui->note->setObjectName ("toolButton");
    this->setObjectName ("whiteWidget");
    initializeSignals ();
    btn_group = new QButtonGroup(this);
    btn_group->addButton (ui->select);
    btn_group->addButton (ui->line);
    btn_group->addButton (ui->rectangle);
    btn_group->addButton (ui->text);
}

MRReaderToolBar::~MRReaderToolBar()
{
    delete ui;
}

void MRReaderToolBar::initializeSignals()
{
    connect (ui->note, &QPushButton::clicked,
             this, &MRReaderToolBar::hideNoteClicked);
    connect (ui->library, &QPushButton::clicked,
             this, &MRReaderToolBar::backLibraryClicked);
}


void MRReaderToolBar::on_hand_clicked()
{
    if(ui->select->isChecked ())
    {
        ui->select->setChecked (false);
    }
    else if (ui->line->isChecked ()) {
        ui->line->setChecked (false);
    }
    else if (ui->rectangle->isChecked ()) {
        ui->rectangle->setChecked (false);
    }
    else if(ui->text->isChecked ())
    {
        ui->text->setChecked (false);
    }
    emit cursorType (CURSOR::HAND);
}

void MRReaderToolBar::on_select_clicked()
{
    if(ui->select->isChecked ())
    {
        qDebug() << "selectPressed";
        emit cursorType (CURSOR::SELECT);
    }
}

void MRReaderToolBar::on_line_clicked()
{
    if(ui->line->isChecked ())
    {
        qDebug() << "linePressed";
        emit cursorType (CURSOR::LINE);
    }
}

void MRReaderToolBar::on_rectangle_clicked()
{
    if(ui->rectangle->isChecked ())
    {
        qDebug() << "rectanglePressed";
        emit cursorType (CURSOR::RECTANGLE);
    }
}

void MRReaderToolBar::on_text_clicked()
{
    if(ui->text->isChecked ())
    {
        qDebug() << "textPressed";
        emit cursorType (CURSOR::TEXT);
    }
}
