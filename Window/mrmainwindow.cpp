#include "mrmainwindow.h"
#include "ui_mrmainwindow.h"
#include "mrlibrary.h"
#include "MRArticleDisplayer.h"
#include "mrarticlereader.h"
#include "mrmessagebox.h"
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
    if(w->setArticle (article))
    {
        QWidget *cur = container->currentWidget ();
        container->removeWidget (cur);
        container->addWidget (w);
        connect (w, &MRArticleReader::backToLibrary,
                 this, &MRMainWindow::switchLibrary);
    }
    else {
        MRMessageBox msg;
        msg.exec ();
    }

}

void MRMainWindow::switchLibrary()
{
    QWidget *cur = container->currentWidget ();
    MRArticleReader *reader = qobject_cast<MRArticleReader*>(cur);
    delete reader;
    container->removeWidget (cur);
    container->addWidget (library);
}
