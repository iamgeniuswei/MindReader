#ifndef ARTICLESCANNER_H
#define ARTICLESCANNER_H

#include <QObject>
#include <QThread>

class ArticleScanner : public QThread
{
    Q_OBJECT
public:
    explicit ArticleScanner(QObject *parent = nullptr);
    virtual void run();

signals:
    void itemReady(const QString& text);
public slots:
};

#endif // ARTICLESCANNER_H
