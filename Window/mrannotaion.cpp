#include "mrannotaion.h"

MRAnnotaion::MRAnnotaion()
{

}

QPoint MRAnnotaion::getStart() const
{
    return start;
}

void MRAnnotaion::setStart(QPoint value)
{
    start = value;
}

QPoint MRAnnotaion::getEnd() const
{
    return end;
}

void MRAnnotaion::setEnd(QPoint value)
{
    end = value;
}

QString MRAnnotaion::getText() const
{
    return text;
}

void MRAnnotaion::setText(const QString &value)
{
    text = value;
}

QColor MRAnnotaion::getColor() const
{
    return color;
}

void MRAnnotaion::setColor(const QColor &value)
{
    color = value;
}

MRAnnotaion::ANNOTATION MRAnnotaion::getType() const
{
    return type;
}

void MRAnnotaion::setType(const MRAnnotaion::ANNOTATION &value)
{
    type = value;
}
