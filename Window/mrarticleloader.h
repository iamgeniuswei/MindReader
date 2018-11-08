#ifndef MRARTICLELOADER_H
#define MRARTICLELOADER_H

#include <QThread>

class MRArticleLoader : public QThread
{
    Q_OBJECT
public:
    explicit MRArticleLoader(QObject *parent = nullptr);

    void loadArticle(const QString& path);

protected:
    virtual void run() override;



signals:

public slots:

private:
    QString articlePath;

};

#endif // MRARTICLELOADER_H
