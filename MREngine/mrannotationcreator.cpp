#include "mrannotationcreator.h"
#include "mupdf/pdf.h"
#include "mrlineannotation.h"
#include "mrsquareannotation.h"
#include "mrtextannotation.h"
#include "mrhighlightannotation.h"
#include <QDebug>
MRAnnotationCreator::MRAnnotationCreator()
{

}

std::shared_ptr<MRAnnotation> MRAnnotationCreator::loadAnnotation(int type,
                                                                    fz_context *ctx,
                                                                    pdf_annot* annot)
{
    switch (type)
    {
    case PDF_ANNOT_LINE:
        return loadLine (ctx, annot);
        break;
    case PDF_ANNOT_SQUARE:
        return loadSquare (ctx, annot);
        break;
    case PDF_ANNOT_TEXT:
        return loadText (ctx, annot);
        break;
    case PDF_ANNOT_HIGHLIGHT:
        return loadHighlight (ctx, annot);
        break;
    default:
        return nullptr;
    }
}

SPtrMRA MRAnnotationCreator::loadLine(fz_context *ctx, pdf_annot *annot)
{
//    Q_ASSERT (ctx != nullptr );
//    Q_ASSERT (annot != nullptr );
//    try
//    {
//        SPtrMRLA annotation = std::make_shared<MRLineAnnotation>(PDF_ANNOT_LINE);
//        pdf_annot_line (ctx, annot, &(annotation->start), &(annotation->end));
//        return annotation;

//    } catch (std::exception &e)
//    {
//        qDebug() << e.what ();
//        return nullptr;
//    }
    return  nullptr;
}

SPtrMRSA MRAnnotationCreator::loadSquare(fz_context *ctx, pdf_annot *annot)
{
//    Q_ASSERT (ctx != nullptr );
//    Q_ASSERT (annot != nullptr );
//    try
//    {
//        SPtrMRSA annotation = std::make_shared<MRSquareAnnotation>(PDF_ANNOT_SQUARE);
//        annotation->rect = pdf_annot_rect (ctx, annot);
//        return annotation;

//    } catch (std::exception &e)
//    {
//        qDebug() << e.what ();
//        return nullptr;
//    }
    return  nullptr;
}

SPtrMRTA MRAnnotationCreator::loadText(fz_context *ctx, pdf_annot *annot)
{
//    Q_ASSERT (ctx != nullptr );
//    Q_ASSERT (annot != nullptr );
//    try
//    {
//        SPtrMRTA annotation = std::make_shared<MRTextAnnotation>(PDF_ANNOT_SQUARE);
//        annotation->rect = pdf_annot_rect (ctx, annot);
//        annotation->content = pdf_annot_contents (ctx, annot);
//        return annotation;

//    } catch (std::exception &e)
//    {
//        qDebug() << e.what ();
//        return nullptr;
//    }
    return nullptr;
}

SPtrMRHA MRAnnotationCreator::loadHighlight(fz_context *ctx, pdf_annot *annot)
{
//    Q_ASSERT (ctx != nullptr );
//    Q_ASSERT (annot != nullptr );
//    try
//    {
//        SPtrMRHA annotation = std::make_shared<MRHighlightAnnotation>(PDF_ANNOT_HIGHLIGHT);
////        annotation->rect = pdf_annot_rect (ctx, annot);
//        float *qu = new float[8];
//        pdf_annot_quad_point (ctx, annot, 1, qu);
//        memcpy (&annotation->quad, qu, sizeof (fz_quad));
//        return annotation;

//    } catch (std::exception &e)
//    {
//        qDebug() << e.what ();
//        return nullptr;
//    }
    return nullptr;
}

SPtrMRA MRAnnotationCreator::createAnnotation(int type)
{
    switch (type)
    {
    case PDF_ANNOT_LINE:
        return std::make_shared<MRLineAnnotation>(PDF_ANNOT_LINE);
        break;
    case PDF_ANNOT_SQUARE:
        return std::make_shared<MRSquareAnnotation>(PDF_ANNOT_SQUARE);
        break;
    case PDF_ANNOT_TEXT:
        return std::make_shared<MRTextAnnotation>(PDF_ANNOT_TEXT);
        break;
    case PDF_ANNOT_HIGHLIGHT:
        return std::make_shared<MRHighlightAnnotation>(PDF_ANNOT_HIGHLIGHT);
        break;
    default:
        return nullptr;
    }
}

void MRAnnotationCreator::appendAnnotation(int type, fz_context *ctx, pdf_annot *annot, const fz_rect &rect, const fz_point &start, const fz_point &end, const fz_quad &quad, const char *content)
{
    switch (type)
    {
    case PDF_ANNOT_LINE:
        appendLine (ctx, annot, start, end);
        break;
    case PDF_ANNOT_SQUARE:
        appendSquare (ctx, annot, rect);
        break;
    case PDF_ANNOT_TEXT:
        appendText (ctx, annot, rect, content);
        break;
    case PDF_ANNOT_HIGHLIGHT:
        appendHighlight (ctx, annot, quad);
        break;
    default:
        break;
    }
}

void MRAnnotationCreator::appendLine(fz_context *ctx, pdf_annot *annot, const fz_point &start, const fz_point &end)
{
    fz_try(ctx)
    {
        Q_ASSERT (annot);
        pdf_set_annot_flags (ctx,
                             annot,
                             PDF_ANNOT_LINE);
        pdf_set_annot_line (ctx,
                            annot,
                            start,
                            end);
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRAnnotationCreator::appendSquare(fz_context *ctx, pdf_annot *annot, const fz_rect &rect)
{
    fz_try(ctx)
    {
        Q_ASSERT (annot);
        pdf_set_annot_flags (ctx,
                             annot,
                             PDF_ANNOT_SQUARE);
        pdf_set_annot_rect(ctx,
                           annot,
                           rect);
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRAnnotationCreator::appendText(fz_context *ctx, pdf_annot *annot, const fz_rect &rect, const char *content)
{
    fz_try(ctx)
    {
        Q_ASSERT (annot);
        pdf_set_annot_flags (ctx,
                             annot,
                             PDF_ANNOT_TEXT);
        pdf_set_annot_rect(ctx,
                           annot,
                           rect);
        if(content != nullptr)
            pdf_set_annot_contents (ctx,
                                    annot,
                                    content);
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}

void MRAnnotationCreator::appendHighlight(fz_context *ctx, pdf_annot *annot, const fz_quad &quad)
{
    fz_try(ctx)
    {
        Q_ASSERT (annot);
        pdf_set_annot_flags (ctx,
                             annot,
                             PDF_ANNOT_HIGHLIGHT);
        float *qu = new float[8];
        memcpy (qu, &quad, sizeof (fz_quad));
        pdf_set_annot_quad_points (ctx, annot, 1, qu);
//        pdf_add_annot_quad_point(ctx,
//                           annot,
//                           quad);
    }
    fz_catch (ctx)
    {
        qDebug() << fz_caught_message (ctx);
    }
}
