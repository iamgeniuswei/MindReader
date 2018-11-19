//#include "mainwindow.h"
#include <QApplication>
#include "mrarticleshelf.h"
#include "qimagetextwidget.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "mrmainwindow.h"
#include "mrarticlecanvas.h"
#include <QDebug>
//#include "ArticlePage.h"
#include "mrarticlereader.h"
#include "notecard.h"
#include "notedisplayer.h"
#include "readerwithnote.h"
#include <QFile>
#include "mrsetting.h"
#include "mrworkdirsettingwindow.h"
#include "mrlibrarytoolbar.h"
#include "ORMHelper.h"
#include "memory"
#include "mrarticlemetadata.h"
#include "mrarticleitem.h"
#include "mrpage.h"
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include "mrlibrarytree.h"
#include "uitextedit.h"
#include "notecard.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType<std::shared_ptr<MRArticleMetaData>>("std::shared_ptr<MRArticleMetaData>");
    qRegisterMetaType<std::shared_ptr<MRPage>>("std::shared_ptr<MRPage>");
    qRegisterMetaType<std::shared_ptr<MRDocument>>("std::shared_ptr<MRDocument>");

	MRSetting *set = MRSetting::instance();
	QString path = QApplication::applicationDirPath();
    set->initializeSetting (path, "/config.ini");
    QString qss = set->getStyleSheet ();
    if(!qss.isEmpty ())
    {
        qss.insert (0, ":/qss/");
        QFile qssFile(qss);
        qssFile.open (QFile::ReadOnly);
        qApp->setStyleSheet (qssFile.readAll ());
        qssFile.close ();
    }
    QString isNew = set->getFirstUseage ();
    QWidget *w = nullptr;
//    NoteCard *w = nullptr;
    qDebug() << set->getWorkDirectory ();

    QString dbname = set->getDatabaseName ();
    QString sqlite_path = set->getWorkDirectory () + "/" + dbname;
    ORMHelper::initializeSqlite (sqlite_path.toStdString ());
    ORMHelper::initializeTables ();

    qDebug() << "QWidget size: " << sizeof(QWidget);
    qDebug() << "QGraphicsTextItem size: " << sizeof(QGraphicsTextItem);
    if(isNew == "true")
    {
        w = new MRWorkDirSettingWindow;
        w->show ();
    }
    else
    {
//        w = new MRArticleItem;
        w = new MRMainWindow;
//        w = new MRLibraryTree;
        //w = new UITextEdit;
		//w = new NoteCard;
		//w = new MRMapView;
        w->show ();
    }

   return a.exec();
}
