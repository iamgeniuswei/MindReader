#include "mainwindow.h"
#include <QApplication>
#include "articleshelf.h"
#include "qimagetextwidget.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "mainwindow.h"
#include "ArticleDisplayer.h"
#include <QDebug>
#include "ArticlePage.h"
#include "articlereader.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;

//    ArticleShelf w;
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
    ArticleReader w;

    w.show();
    qDebug() << "w:" << w.size ();
    return a.exec();
}
