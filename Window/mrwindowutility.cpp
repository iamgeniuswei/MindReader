
#include "mrwindowutility.h"
#include <QFont>
#include <QFontMetrics>
QString getElidedText(const QString &str, const QFont& font,  int maxWidth)
{
    Q_ASSERT (maxWidth > 0);
    QString ret = str;
    QFontMetrics fontMetrics(font);
    int width = fontMetrics.width (str);
    if(width >= maxWidth)
    {
        ret = fontMetrics.elidedText (str, Qt::ElideRight, maxWidth);
    }
    return ret;
}

