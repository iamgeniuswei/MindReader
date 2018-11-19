#include "mrsquareannotation.h"
#include "PDFUtil.h"
#include <QDebug>
MRSquareAnnotation::MRSquareAnnotation(int type)
    :MRAnnotation (type)
{

}

void MRSquareAnnotation::loadFromPage(fz_context *ctx, pdf_annot *annot)
{
    Q_ASSERT (ctx != nullptr );
    Q_ASSERT (annot != nullptr );
    if(ctx == nullptr || annot == nullptr)
    {
        return;
    }
    fz_try (ctx)
    {
        rect = pdf_annot_rect (ctx, annot);
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRSquareAnnotation::appendToPage(fz_context *ctx, pdf_annot *annot, void *data, float *scolor)
{
    Q_ASSERT (ctx != nullptr );
    Q_ASSERT (annot != nullptr );
    Q_ASSERT (data != nullptr);
    if(ctx == nullptr || annot == nullptr || data == nullptr)
    {
        return;
    }
    fz_rect *r = reinterpret_cast<fz_rect*>(data);
    memcpy (&rect, r, sizeof (fz_rect));
    memcpy (color, scolor, 3*sizeof (float));
    fz_try (ctx)
    {
        pdf_set_annot_rect (ctx, annot, rect);
        pdf_set_annot_color (ctx, annot, 3, color);
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRSquareAnnotation::draw(QPainter &painter, float scaleX, float scaleY, float rotation)
{
        fz_rect r = mapFromOrigin (rect,
                                      scaleX,
                                      scaleY,
                                      rotation);

        QRectF qrect(QPointF(r.x0,r.y0),
                    QPointF(r.x1, r.y1));
        QColor qcolor;
        qcolor.setRgbF (color[0], color[1], color[2]);
        painter.save ();
        QPen pen(qcolor, 2);
        painter.setPen (pen);
        painter.setRenderHint (QPainter::Antialiasing);
        painter.drawRect (qrect);
        painter.restore ();
}

