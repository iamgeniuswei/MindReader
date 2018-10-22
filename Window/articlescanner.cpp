#include "articlescanner.h"
#include <QDir>
#include <QStringList>
ArticleScanner::ArticleScanner(QObject *parent) : QThread(parent)
{

}

void ArticleScanner::run()
{
    QDir dir("D:\\Article");
    QStringList list = dir.entryList (QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot, QDir::DirsFirst);
    for(int i=0; i<list.size (); i++)
    {
        emit itemReady (list.at (i));
    }
}
