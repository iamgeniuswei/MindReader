#ifndef ARTICLEPAGERENDER_H
#define ARTICLEPAGERENDER_H

#include <QObject>
#include <QThread>
#include <QImage>
#include <memory>
#include "fifotsqueue.h"
class MRDocument;
class MRPage;
class ArticlePageRender : public QThread
{
    Q_OBJECT
public:
    explicit ArticlePageRender(QObject *parent = nullptr);
    virtual void run();

public:
    void requestPage(int page, float scaleX, float scaleY, float rotation);
    void requestPage(int sIndex, int eIndex, float scaleX, float scaleY, float rotation);
    void setPDFDocument(std::shared_ptr<MRDocument> document = nullptr);
    void retDocument();
signals:
    void pageReady(float scaleX,
                   float scaleY,
                   float rotation,
                   int index,
                   QImage img,
                   std::shared_ptr<MRPage> page);

public slots:

private:
    float scaleX = 1.0;
    float scaleY = 1.0;
    float rotation = 0.0;
    std::shared_ptr<MRDocument> doc = nullptr;
    int pageIndex = 0;
    int sIndex = 0;
    int eIndex = 0;
    FIFOTSQueue<int> pendingIndex;
};

#endif // ARTICLEPAGERENDER_H
