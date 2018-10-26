//#include "mainwindow.h"
#include <QApplication>
#include "articleshelf.h"
#include "qimagetextwidget.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "mrmainwindow.h"
#include "ArticleDisplayer.h"
#include <QDebug>
#include "ArticlePage.h"
#include "articlereader.h"
#include "notecard.h"
#include "notedisplayer.h"
#include "readerwithnote.h"
#include <QFile>
#include "mrsetting.h"
#include "mrworkdirsettingwindow.h"
#include "mrlibrarytoolbar.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MRSetting set;
    set.initializeSetting ("config.ini");
    QString qss = set.getStyleSheet ();
    if(!qss.isEmpty ())
    {
        qss.insert (0, ":/qss/");
        QFile qssFile(qss);
        qssFile.open (QFile::ReadOnly);
        qApp->setStyleSheet (qssFile.readAll ());
        qssFile.close ();
    }
    QString isNew = set.getFirstUseage ();
    QWidget *w = nullptr;
    qDebug() << set.getWorkDirectory ();

    if(isNew == "true")
    {
        w = new MRWorkDirSettingWindow;
        w->show ();
    }
    else
    {
//        w = new ArticleShelf;
        w = new MRMainWindow;
//        w = new MRLibraryToolBar;
        w->show ();
    }

//    MainWindow w;

//    ArticleShelf w;
//    MRWorkDirSettingWindow w;
//    QImageTextWidget w;
//    w.setImage (":/img/pdf");
//    w.setText ("DFDSFSDFSDF");

//    QListWidget w;
//    w.setCurrentRow (10);
//    w.setResizeMode(QListView::Adjust);

//    QListWidgetItem *it1 = new QListWidgetItem(&w);
//    it1->setSizeHint (QSize(200,200));
//    QImageTextWidget *w1 = new QImageTextWidget(&w);
//    w1->setImage (":/img/pdf");
//    w.addItem (it1);
//    w.setItemWidget (it1, w1);
//    QListWidgetItem *it2 = new QListWidgetItem(&w);
//    it2->setSizeHint (QSize(200,200));
//    QImageTextWidget *w2 = new QImageTextWidget(&w);
//    w2->setImage (":/img/pdf");
//    w.addItem (it2);
//    w.setItemWidget (it2, w2);
//    w.setViewMode (QListView::IconMode);
//    ArticleShelf w;
//    MainWindow w;
//    ArticleDisplayer w;
//    w.setAlignment (Qt::AlignHCenter);
//    ArticlePage w;
//    ArticleReader w;
//    NoteCard w;
//    NoteDisplayer w;

//    ReaderWithNote w;

//    w.show();
//    qDebug() << "w:" << w.size ();
    return a.exec();
}
