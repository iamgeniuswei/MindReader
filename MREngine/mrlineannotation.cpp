#include "mrlineannotation.h"
#include <QPainter>
#include "PDFUtil.h"
MRLineAnnotation::MRLineAnnotation(int type)
    :MRAnnotation (type)
{

}

void MRLineAnnotation::draw(QPainter &painter, float scaleX, float scaleY, float rotation)
{
        fz_rect r = mapFromOrigin (rect,
                                      scaleX,
                                      scaleY,
                                      rotation);

        fz_point o_start = mapFromOrigin (start, scaleX,scaleY,rotation);
        fz_point o_end = mapFromOrigin (end, scaleX, scaleY, rotation);

//        QPointF start(r.x0, r.y0);
//        QPointF end(r.x1, r.y1);
        QPointF start(o_start.x, o_start.y);
        QPointF end(o_end.x, o_end.y);
    //    QPainter painter;
        painter.save ();
        QPen pen(Qt::red, 2);
        painter.setPen (pen);
        painter.setRenderHint (QPainter::Antialiasing);
        painter.drawLine(start, end);
        painter.restore ();
}
