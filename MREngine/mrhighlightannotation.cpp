#include "mrhighlightannotation.h"
#include "PDFUtil.h"
#include <QDebug>
MRHighlightAnnotation::MRHighlightAnnotation(int type)
    :MRAnnotation (type)
{

}

void MRHighlightAnnotation::loadFromPage(fz_context *ctx, pdf_annot *annot)
{
    Q_ASSERT (ctx != nullptr );
    Q_ASSERT (annot != nullptr );
    if(ctx == nullptr || annot == nullptr)
    {
        return;
    }
    fz_try (ctx)
    {
        if(pdf_annot_has_quad_points (ctx, annot))
        {
            pdf_annot_quad_point (ctx, annot, 0, (float*)(&quad));
        }
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRHighlightAnnotation::appendToPage(fz_context *ctx, pdf_annot *annot, void *data, float *scolor)
{
    Q_ASSERT (ctx != nullptr );
    Q_ASSERT (annot != nullptr );
    Q_ASSERT (data != nullptr);
    if(ctx == nullptr || annot == nullptr || data == nullptr)
    {
        return;
    }
    fz_quad *quads = reinterpret_cast<fz_quad*>(data);
    memcpy (&quad, quads, sizeof (fz_quad));
    memcpy (color, scolor, 3*sizeof (float));

    fz_try (ctx)
    {
        pdf_add_annot_quad_point (ctx, annot, quad);
        pdf_set_annot_color (ctx, annot, 3, color);
        pdf_set_annot_opacity (ctx, annot, 0.6);
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRHighlightAnnotation::draw(QPainter &painter, float scaleX, float scaleY, float rotation)
{

        fz_quad r = mapFromOrigin (quad,
                                      scaleX,
                                      scaleY,
                                      rotation);
        QRectF qrect(QPointF(r.ul.x,r.ul.y),
                    QPointF(r.lr.x, r.lr.y));
        QColor qcolor;
        qcolor.setRgbF (color[0], color[1], color[2], 0.6);
        painter.save ();
        painter.fillRect (qrect,
                          qcolor);
        painter.restore ();
}
