#include "articlescanner.h"
#include <QDir>
#include <QStringList>
#include "mrsetting.h"
#include "ORMHelper.h"
#include "mrarticlemetadata.h"
#include <memory>
#include <QDebug>
ArticleScanner::ArticleScanner(QObject *parent) : QThread(parent)
{

}

void ArticleScanner::run()
{
    MRSetting set;
    set.initializeSetting ("config.ini");
    QString working_dir = set.getWorkDirectory ();
    if(!working_dir.isEmpty ())
    {
        QDir dir(working_dir);
        QStringList dir_list = dir.entryList (QDir::Dirs|QDir::NoDotAndDotDot, QDir::DirsFirst);
        for(int i=0; i<dir_list.size (); i++)
        {
            handleFolderMetaData (dir_list.at(i));
        }
        QStringList file_list = dir.entryList (QDir::Files|QDir::NoDotAndDotDot, QDir::DirsFirst);
        for(int i=0; i<file_list.size (); i++)
        {
            handleArticleMetaData (file_list.at(i));
        }
    }
}

void ArticleScanner::scanDirsRecurSively(const QString &root)
{


}

void ArticleScanner::scanFilesInDir()
{

}

void ArticleScanner::handleArticleMetaData(const QString& file_name)
{
    std::shared_ptr<MRArticleMetaData> article = std::make_shared<MRArticleMetaData>();
    if(article != nullptr)
    {
        article->setTitle (file_name.toStdString ());
        qDebug()<< article->persist ();
        emit itemReady (article);
    }

}

void ArticleScanner::handleFolderMetaData(const QString& folder_name)
{
//    emit itemReady (folder_name);
}
