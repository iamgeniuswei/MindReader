#ifndef MRANNOTATIONCREATOR_H
#define MRANNOTATIONCREATOR_H

class MRAnnotation;
#include <memory>
#include "pdfcore_global.h"
#include "PDFUtil.h"
class PDFCORESHARED_EXPORT MRAnnotationCreator
{
public:
    MRAnnotationCreator();
    static std::shared_ptr<MRAnnotation> loadAnnotation(int type,
                                                          fz_context *ctx,
                                                          pdf_annot *annot);
    static SPtrMRA loadLine(fz_context *ctx,
                              pdf_annot *annot);
    static SPtrMRSA loadSquare(fz_context *ctx,
                              pdf_annot *annot);
    static SPtrMRTA loadText(fz_context *ctx,
                               pdf_annot *annot);
    static SPtrMRHA loadHighlight(fz_context *ctx,
                                    pdf_annot *annot);
    static SPtrMRA createAnnotation(int type);

    static void appendAnnotation(int type,
                                 fz_context *ctx,
                                 pdf_annot *annot,
                                 const fz_rect& rect,
                                 const fz_point &start,
                                 const fz_point &end,
                                 const fz_quad &quad,
                                 const char *content);
    static void appendLine(fz_context *ctx,
                           pdf_annot *annot,
                           const fz_point &start,
                           const fz_point &end);
    static void appendSquare(fz_context *ctx,
                             pdf_annot *annot,
                             const fz_rect& rect);
    static void appendText(fz_context *ctx,
                             pdf_annot *annot,
                             const fz_rect& rect,
                            const char* content);
    static void appendHighlight(fz_context *ctx,
                                pdf_annot *annot,
                                const fz_quad& quad);
};

#endif // MRANNOTATIONCREATOR_H
