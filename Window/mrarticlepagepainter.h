#ifndef MRARTICLEPAGEPAINTER_H
#define MRARTICLEPAGEPAINTER_H
#include <QPainter>
#include "mrwindowutility.h"
class MRArticlePagePainter
{
public:
    MRArticlePagePainter();
    static void drawFollowMouse(QPainter &painter,
                                const QColor &color,
                                CURSOR cursor,
                                const QPoint &start,
                                const QPoint &end);
private:
    static void drawLine(QPainter &painter,
                         const QColor &color,
                         const QPoint &start,
                         const QPoint &end);
    static void drawRectangle(QPainter &painter,
                              const QColor &color,
                              const QPoint &start,
                         const QPoint &end);
    static void drawSelection(QPainter &painter,
                              const QColor &color,
                              const QPoint &start,
                         const QPoint &end);

};

#endif // MRARTICLEPAGEPAINTER_H
