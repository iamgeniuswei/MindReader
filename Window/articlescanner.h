#ifndef ARTICLESCANNER_H
#define ARTICLESCANNER_H

#include <QObject>
#include <QThread>
#include "mrarticlemetadata.h"
class ArticleScanner : public QThread
{
    Q_OBJECT
public:
    explicit ArticleScanner(QObject *parent = nullptr);
    virtual void run();

signals:
    void itemReady(std::shared_ptr<MRArticleMetaData> aritcle);
public slots:

private:
    void scanDirsRecurSively(const QString& root);
    void scanFilesInDir();
    void handleArticleMetaData(const QString &file_name);
    void handleFolderMetaData(const QString &folder_name);
};

#endif // ARTICLESCANNER_H
