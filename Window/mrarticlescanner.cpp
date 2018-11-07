#include "mrarticlescanner.h"
#include <QDir>
#include <QStringList>
#include "mrsetting.h"
#include "ORMHelper.h"
#include "mrarticlemetadata.h"
#include <memory>
#include <QDebug>
MRArticleScanner::MRArticleScanner(QObject *parent) : QThread(parent)
{

}

void MRArticleScanner::run()
{
//    MRSetting set;
//    set.initializeSetting ("config.ini");
//    QString working_dir = set.getWorkDirectory ();
    QStringList filters;
    filters << "*.pdf" << "*.xps" << "*.doc" << "*.ppt";

    if(!currentDir.isEmpty ())
    {
        QDir dir(currentDir);

        QStringList dir_list = dir.entryList (QDir::Dirs|QDir::NoDotAndDotDot, QDir::DirsFirst);
        for(int i=0; i<dir_list.size (); i++)
        {
            handleFolderMetaData (dir_list.at(i));
        }
        dir.setNameFilters(filters);
        QStringList file_list = dir.entryList (QDir::Files|QDir::NoDotAndDotDot, QDir::DirsFirst);
        for(int i=0; i<file_list.size (); i++)
        {
            handleArticleMetaData (file_list.at(i));
        }
    }
}

void MRArticleScanner::startScan(const QString &dir)
{
    if(!dir.isEmpty ())
    {
        currentDir = dir;
        start (QThread::HighestPriority);
    }
}

void MRArticleScanner::scanDirsRecurSively(const QString &root)
{


}

void MRArticleScanner::scanFilesInDir()
{

}

void MRArticleScanner::handleArticleMetaData(const QString& file_name)
{
    std::shared_ptr<MRArticleMetaData> article = std::make_shared<MRArticleMetaData>();
    if(article != nullptr)
    {
        QString absolute_dir = currentDir + "/" + file_name;
        article->setTitle (file_name.toStdString ());
        article->setRelative_path (absolute_dir.toStdString ());
//        qDebug() << article->exist (article->title (),
//                                    article->relative_path ());
        if(article->persist () == 0)
        {
            article->query ();
        }

        emit ArticleReady (article);
    }

}

void MRArticleScanner::handleFolderMetaData(const QString& folder_name)
{
    emit folderReady (folder_name);
}
