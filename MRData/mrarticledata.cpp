#include "mrarticledata.h"

MRArticleData::MRArticleData()
{

}

QString MRArticleData::getFileName() const
{
    return fileName;
}

void MRArticleData::setFileName(const QString &value)
{
    fileName = value;
}

QString MRArticleData::getRelativePath() const
{
    return relativePath;
}

void MRArticleData::setRelativePath(const QString &value)
{
    relativePath = value;
}

QString MRArticleData::getAuthor() const
{
    return author;
}

void MRArticleData::setAuthor(const QString &value)
{
    author = value;
}

int MRArticleData::getPageCount() const
{
    return pageCount;
}

void MRArticleData::setPageCount(int value)
{
    pageCount = value;
}

MRArticleData::TYPE MRArticleData::getType() const
{
    return type;
}


void MRArticleData::setType(const TYPE &value)
{
    type = value;
}
