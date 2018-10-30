#ifndef MRANNOATAION_H
#define MRANNOATAION_H
#include <QObject>
#include <QPoint>
#include <QPointF>
#include <QColor>
#include "mrwindowutility.h"
class MRAnnotaion
{
public:
    enum ANNOTATION
    {
        HIGHLIGHT,
        LINE,
        RECTANGLE,
        TEXT
    };
public:
    MRAnnotaion();


    QPoint getStart() const;
    void setStart(QPoint value);

    QPoint getEnd() const;
    void setEnd(QPoint value);

    QString getText() const;
    void setText(const QString &value);

    QColor getColor() const;
    void setColor(const QColor &value);

    ANNOTATION getType() const;
    void setType(const ANNOTATION &value);

private:
    ANNOTATION type;
    QPoint start;
    QPoint end;
    QString text;
    QColor color;
};

#endif // MRANNOATAION_H
