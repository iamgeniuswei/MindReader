#ifndef MRWINDOWUTILITY_H
#define MRWINDOWUTILITY_H


#include "window_global.h"
#include <QFont>
enum class CURSOR
{
    HAND,
    SELECT,
    LINE,
    RECTANGLE,
    TEXT
};

enum class PAGEFORM
{
    SINGLE,
    CONTINUOUS
};



WINDOWSHARED_EXPORT QString getElidedText(const QString &str, const QFont &font, int maxWidth);
#endif // MRWINDOWUTILITY_H
