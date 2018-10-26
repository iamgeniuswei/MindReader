#include "mrlibrarytoolbar.h"
#include "ui_mrlibrarytoolbar.h"
#include <QAction>
MRLibraryToolBar::MRLibraryToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MRLibraryToolBar)
{
    ui->setupUi(this);
    QAction *action = new QAction(ui->lineEdit);
    action->setIcon (QIcon(":/img/search"));
    ui->lineEdit->addAction (action, QLineEdit::TrailingPosition);
    ui->lineEdit->setObjectName ("search");
}

MRLibraryToolBar::~MRLibraryToolBar()
{
    delete ui;
}
