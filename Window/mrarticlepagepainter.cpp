#include "mrarticlepagepainter.h"

MRArticlePagePainter::MRArticlePagePainter()
{

}

void MRArticlePagePainter::drawFollowMouse(QPainter &painter, CURSOR cursor, const QPoint &start, const QPoint &end)
{
    switch (cursor)
    {
    case CURSOR::LINE:
        drawLine (painter, start, end);
        break;
    case CURSOR::RECTANGLE:
        drawRectangle (painter, start, end);
        break;
    }
}

void MRArticlePagePainter::drawLine(QPainter &painter, const QPoint &start, const QPoint &end)
{
    //    QPainter painter;
        painter.save ();
        QPen pen(Qt::red, 2);
        painter.setPen (pen);
        painter.setRenderHint (QPainter::Antialiasing);
        painter.drawLine (start, end);
        painter.restore ();
}

void MRArticlePagePainter::drawRectangle(QPainter &painter, const QPoint &start, const QPoint &end)
{
    painter.save ();
    QPen pen(Qt::red, 2);
    painter.setPen (pen);
    painter.setRenderHint (QPainter::Antialiasing);
    QRect rect(start, end);
    painter.drawRect (rect);
    painter.restore ();
}

void MRArticlePagePainter::drawSelection(QPainter &painter, const QPoint &start, const QPoint &end)
{
    painter.save ();
    QRect rect(start, end);
    painter.fillRect (rect, QBrush(QColor(18, 150, 219, 100)));
    painter.restore ();
}
