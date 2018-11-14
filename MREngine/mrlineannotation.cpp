#include "mrlineannotation.h"
#include <QPainter>
#include "PDFUtil.h"
#include <QDebug>
MRLineAnnotation::MRLineAnnotation(int type)
    :MRAnnotation (type)
{

}

void MRLineAnnotation::loadFromPage(fz_context *ctx, pdf_annot *annot)
{
    Q_ASSERT (ctx != nullptr );
    Q_ASSERT (annot != nullptr );
    if(ctx == nullptr || annot == nullptr)
    {
        return;
    }
    fz_try (ctx)
    {
        if(pdf_annot_has_line (ctx, annot))
        {
            pdf_annot_line (ctx, annot, &start, &end);
        }
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRLineAnnotation::appendToPage(fz_context *ctx, pdf_annot *annot, void *data, float *scolor)
{
    Q_ASSERT (ctx != nullptr );
    Q_ASSERT (annot != nullptr );
    Q_ASSERT (data != nullptr);
    if(ctx == nullptr || annot == nullptr || data == nullptr)
    {
        return;
    }
    if(scolor != nullptr)
    {
        memcpy (color, scolor, 3*sizeof (float));
    }
    fz_point *points = reinterpret_cast<fz_point*>(data);
    memcpy (&start, points, sizeof (fz_point));
    memcpy (&end, points+1, sizeof (fz_point));
    memcpy (color, scolor, 3*sizeof (float));
    fz_try (ctx)
    {
        pdf_set_annot_line (ctx, annot, start, end);        
        pdf_set_annot_color (ctx, annot, 3, color);
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRLineAnnotation::draw(QPainter &painter, float scaleX, float scaleY, float rotation)
{
        fz_point o_start = mapFromOrigin (start, scaleX,scaleY,rotation);
        fz_point o_end = mapFromOrigin (end, scaleX, scaleY, rotation);

//        QPointF start(r.x0, r.y0);
//        QPointF end(r.x1, r.y1);
        QPointF start(o_start.x, o_start.y);
        QPointF end(o_end.x, o_end.y);
        QColor qcolor;
        qcolor.setRgbF (color[0], color[1], color[2]);
    //    QPainter painter;
        painter.save ();
        QPen pen(qcolor, 2);
        painter.setPen (pen);
        painter.setRenderHint (QPainter::Antialiasing);
        painter.drawLine(start, end);
        painter.restore ();
}
