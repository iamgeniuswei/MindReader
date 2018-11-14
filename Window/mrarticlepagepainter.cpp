#include "mrarticlepagepainter.h"

MRArticlePagePainter::MRArticlePagePainter()
{

}

void MRArticlePagePainter::drawFollowMouse(QPainter &painter, const QColor &color, CURSOR cursor, const QPoint &start, const QPoint &end)
{
    switch (cursor)
    {
    case CURSOR::LINE:
        drawLine (painter, color, start, end);
        break;
    case CURSOR::RECTANGLE:
        drawRectangle (painter, color, start, end);
        break;
    case CURSOR::SELECT:
        drawSelection (painter, color, start, end);
        break;
    }
}

void MRArticlePagePainter::drawLine(QPainter &painter, const QColor &color, const QPoint &start, const QPoint &end)
{
    //    QPainter painter;
        painter.save ();
        QPen pen(color, 2);
        painter.setPen (pen);
        painter.setRenderHint (QPainter::Antialiasing);
        painter.drawLine (start, end);
        painter.restore ();
}

void MRArticlePagePainter::drawRectangle(QPainter &painter, const QColor &color, const QPoint &start, const QPoint &end)
{
    painter.save ();
    QPen pen(color, 2);
    painter.setPen (pen);
    painter.setRenderHint (QPainter::Antialiasing);
    QRect rect(start, end);
    painter.drawRect (rect);
    painter.restore ();
}

void MRArticlePagePainter::drawSelection(QPainter &painter,const QColor &color, const QPoint &start, const QPoint &end)
{
    QColor opacityColor{color};
    opacityColor.setAlpha (100);
    painter.save ();
    QRect rect(start, end);
    painter.fillRect (rect, opacityColor);
    painter.restore ();
}
