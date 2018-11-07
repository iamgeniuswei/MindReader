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

    int getType() const;
    void setType(int value);

    fz_rect getRect() const;
    void setRect(const fz_rect &value);

    const char *getContent() const;
    void setContent(const char *value);

public:
    virtual void draw(QPainter& painter, float scaleX, float scaleY, float rotation)  = 0;

    fz_point getStart() const;
    void setStart(const fz_point &value);

    fz_point getEnd() const;
    void setEnd(const fz_point &value);

protected:
    int type;
    fz_rect rect;
    fz_point start;
    fz_point end;
    const char *content = nullptr;
    friend class MRPage;
};

#endif // MRANNOTATION_H
