#ifndef MRARTICLELOADER_H
#define MRARTICLELOADER_H

#include <QThread>
class MRDocument;
class MRArticleLoader : public QThread
{
    Q_OBJECT
public:
    explicit MRArticleLoader(QObject *parent = nullptr);

    void loadArticle(const QString& path);

protected:
    virtual void run() override;



signals:
    void docReady(bool ret, std::shared_ptr<MRDocument> doc);
    void indexReady(const QStringList& items);

public slots:

private:
    QString articlePath;

};

#endif // MRARTICLELOADER_H
