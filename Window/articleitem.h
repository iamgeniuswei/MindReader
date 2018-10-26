#ifndef ARTICLEITEM_H
#define ARTICLEITEM_H

#include <QWidget>
#include "qimagetextwidget.h"
class ArticleItem : public QImageTextWidget
{
    Q_OBJECT
public:
    explicit ArticleItem(QWidget *parent = nullptr);
    virtual void setText(const QString& text);

signals:

public slots:

private:
    QString getElidedText(const QString &str, int maxWidth);

private:
    QString path;
    QString fileName;
};

#endif // ARTICLEITEM_H
