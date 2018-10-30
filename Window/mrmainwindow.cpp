#include "mrmainwindow.h"
#include "ui_mrmainwindow.h"
#include "mrlibrary.h"
#include "ArticleDisplayer.h"
#include "mrarticlereader.h"
MRMainWindow::MRMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MRMainWindow)
{
    ui->setupUi(this);
    container = new QStackedWidget(this);
    library = new MRLibrary(this);
    container->addWidget (library);
    setCentralWidget (container);
    connect (library, &MRLibrary::articleClicked,
             this, &MRMainWindow::switchToAritcle);
}

MRMainWindow::~MRMainWindow()
{
    delete ui;
}

void MRMainWindow::initializeSignals()
{

}

void MRMainWindow::switchToAritcle(std::shared_ptr<MRArticleMetaData> article)
{
//    ArticleDisplayer *w = new ArticleDisplayer;
    MRArticleReader *w = new MRArticleReader;
    w->setArticle (article);
    QWidget *cur = container->currentWidget ();
    container->removeWidget (cur);
    container->addWidget (w);
    connect (w, &MRArticleReader::backToLibrary,
             this, &MRMainWindow::switchLibrary);
}

void MRMainWindow::switchLibrary()
{
    QWidget *cur = container->currentWidget ();
    container->removeWidget (cur);
    container->addWidget (library);
}
