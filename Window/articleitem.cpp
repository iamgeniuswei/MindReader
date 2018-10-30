#include "articleitem.h"
#include <QFontMetrics>
#include <QDebug>
#include "mrarticlemetadata.h"
ArticleItem::ArticleItem(QWidget *parent) : QImageTextWidget(parent)
{
//    data = new (std::nothrow) MRArticleData;
}

ArticleItem::~ArticleItem()
{
//    if(data)
//        delete data;
}

void ArticleItem::setText(const QString &text)
{
//    if(data)
//        data->setFileName (text);
    QString str = getElidedText (text, 120);
    QImageTextWidget::setText (str);
}

void ArticleItem::mouseDoubleClickEvent(QMouseEvent *event)
{
//    if(data)
//    {
//        qDebug() << "ArticleItem clicked";
//        qDebug() << data->getFileName ();
//        emit clicked (data->getFileName ());
//    }
    if(data != nullptr)
    {
        qDebug() << QString::fromStdString (data->title ());
        emit articleClicked (data);
    }
}

QString ArticleItem::getElidedText(const QString& str, int maxWidth)
{
    QString ret = str;
    QFontMetrics fontMetrics(this->font ());
    int width = fontMetrics.width (str);
    if(width >= 120)
    {
        ret = fontMetrics.elidedText (str, Qt::ElideRight, 120);
    }
    return ret;
}

void ArticleItem::setArticle(const std::shared_ptr<MRArticleMetaData> &value)
{
    data = value;
}
