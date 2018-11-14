#ifndef MRANNOTATION_H
#define MRANNOTATION_H

#include "mupdf/pdf.h"
#include "pdfcore_global.h"
#include <QPainter>
class MRPage;


enum class PDF_ANNOT
{
    PDF_ANNOT_TEXT,
    PDF_ANNOT_LINK,
    PDF_ANNOT_FREE_TEXT,
    PDF_ANNOT_LINE,
    PDF_ANNOT_SQUARE,
    PDF_ANNOT_CIRCLE,
    PDF_ANNOT_POLYGON,
    PDF_ANNOT_POLY_LINE,
    PDF_ANNOT_HIGHLIGHT,
    PDF_ANNOT_UNDERLINE,
    PDF_ANNOT_SQUIGGLY,
    PDF_ANNOT_STRIKE_OUT,
    PDF_ANNOT_STAMP,
    PDF_ANNOT_CARET,
    PDF_ANNOT_INK,
    PDF_ANNOT_POPUP,
    PDF_ANNOT_FILE_ATTACHMENT,
    PDF_ANNOT_SOUND,
    PDF_ANNOT_MOVIE,
    PDF_ANNOT_WIDGET,
    PDF_ANNOT_SCREEN,
    PDF_ANNOT_PRINTER_MARK,
    PDF_ANNOT_TRAP_NET,
    PDF_ANNOT_WATERMARK,
    PDF_ANNOT_3D,
    PDF_ANNOT_UNKNOWN = -1
};


class PDFCORESHARED_EXPORT MRAnnotation
{
public:
    MRAnnotation(int flag);
    virtual ~MRAnnotation(){}
    virtual void loadFromPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr) = 0;
    virtual void appendToPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr,
                              void *data = nullptr,
                              float *color = nullptr) = 0;
    virtual void draw(QPainter& painter, float scaleX, float scaleY, float rotation)  = 0;
    int getType() const;
    void setType(int value);

protected:
    int type;
    float color[3];
    friend class MRPage;
    friend class MRAnnotationCreator;
};

#endif // MRANNOTATION_H
