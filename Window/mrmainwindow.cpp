#include "mrmainwindow.h"
#include "ui_mrmainwindow.h"
#include "mrlibrary.h"
#include "ArticleDisplayer.h"
MRMainWindow::MRMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MRMainWindow)
{
    ui->setupUi(this);
    container = new QStackedWidget(this);
    MRLibrary *w = new MRLibrary(this);
    container->addWidget (w);
    setCentralWidget (container);
    connect (w, &MRLibrary::articleClicked,
             this, &MRMainWindow::switchToAritcle);
}

MRMainWindow::~MRMainWindow()
{
    delete ui;
}

void MRMainWindow::switchToAritcle(const QString &text)
{
    ArticleDisplayer *w = new ArticleDisplayer;
    QWidget *cur = container->currentWidget ();
    container->removeWidget (cur);
    container->addWidget (w);
}
