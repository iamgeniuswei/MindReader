#ifndef ARTICLEPAGERENDER_H
#define ARTICLEPAGERENDER_H

#include <QObject>
#include <QThread>
#include <QImage>
class PDFDocument;
class PDFPage;
class ArticlePageRender : public QThread
{
    Q_OBJECT
public:
    explicit ArticlePageRender(QObject *parent = nullptr);
    virtual void run();

public:
    void requestPage(int page, float scaleX, float scaleY, float rotation);
    void setPDFDocument(PDFDocument *document = nullptr);
signals:
    void pageReady(float scaleX, float scaleY, float rotation, int index, QImage img, PDFPage *src);

public slots:

private:
    float scaleX = 1.0;
    float scaleY = 1.0;
    float rotation = 0.0;
    PDFDocument *doc = nullptr;
    int pageIndex = 0;
};

#endif // ARTICLEPAGERENDER_H
