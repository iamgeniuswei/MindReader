#include "mrarticleloader.h"
#include "mrdocument.h"
MRArticleLoader::MRArticleLoader(QObject *parent) : QThread(parent)
{

}

void MRArticleLoader::loadArticle(const QString &path)
{
    articlePath = path;
    start (QThread::HighestPriority);
}

void MRArticleLoader::run()
{
    std::shared_ptr<MRDocument> doc = std::make_shared<MRDocument>();
    if(doc)
    {
        bool ret = doc->openDocument (articlePath);
        if(!ret)
        {
            emit docReady (false, nullptr);
            return;
        }
        QStringList items;
        QString count = QString::number (doc->pageCount ());
        for(int i=0; i<doc->pageCount (); i++)
        {
            items << (QString::number (i) + "/" + count);
        }
        emit indexReady (items);
        emit docReady (true, doc);
    }
    else
    {
        emit docReady (false, nullptr);
    }
}
