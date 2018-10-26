#include "articleitem.h"
#include <QFontMetrics>
ArticleItem::ArticleItem(QWidget *parent) : QImageTextWidget(parent)
{

}

void ArticleItem::setText(const QString &text)
{
    QString str = getElidedText (text, 120);
    QImageTextWidget::setText (str);
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
