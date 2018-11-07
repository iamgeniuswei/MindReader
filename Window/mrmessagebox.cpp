#include "mrmessagebox.h"
#include "ui_mrmessagebox.h"

MRMessageBox::MRMessageBox(QWidget *parent) :
    UIDialog(parent),
    ui(new Ui::MRMessageBox)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setModal (true);
}

MRMessageBox::~MRMessageBox()
{
    delete ui;
}

void MRMessageBox::on_MRMBClose_clicked()
{
    this->close ();
}
