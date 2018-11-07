#ifndef ARTICLESCANNER_H
#define ARTICLESCANNER_H

#include <QObject>
#include <QThread>
#include "mrarticlemetadata.h"
class MRArticleScanner : public QThread
{
    Q_OBJECT
public:
    explicit MRArticleScanner(QObject *parent = nullptr);
    virtual void run();
    void startScan(const QString& dir);

signals:
    void ArticleReady(std::shared_ptr<MRArticleMetaData> aritcle);
    void folderReady(const QString& name);
public slots:

private:
    void scanDirsRecurSively(const QString& root);
    void scanFilesInDir();
    void handleArticleMetaData(const QString &file_name);
    void handleFolderMetaData(const QString &folder_name);
    QString currentDir;
};

#endif // ARTICLESCANNER_H
