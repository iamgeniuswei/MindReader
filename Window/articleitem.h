#ifndef ARTICLEITEM_H
#define ARTICLEITEM_H

#include <QWidget>
#include "qimagetextwidget.h"
#include "mrarticledata.h"
#include <memory>
class MRArticleMetaData;
class ArticleItem : public QImageTextWidget
{
    Q_OBJECT
public:
    explicit ArticleItem(QWidget *parent = nullptr);
    ~ArticleItem();
    virtual void setText(const QString& text);


    void setArticle(const std::shared_ptr<MRArticleMetaData> &value);

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

signals:
    void articleClicked(std::shared_ptr<MRArticleMetaData> article);

public slots:

private:
    QString getElidedText(const QString &str, int maxWidth);

private:
//    MRArticleData *data = nullptr;
    std::shared_ptr<MRArticleMetaData> data = nullptr;
};

#endif // ARTICLEITEM_H
