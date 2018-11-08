#include "mrarticleloader.h"

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

}
