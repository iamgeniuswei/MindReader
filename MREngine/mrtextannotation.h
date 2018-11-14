#ifndef MRTEXTANNOTATION_H
#define MRTEXTANNOTATION_H

#include "mrannotation.h"
class MRTextAnnotation : public MRAnnotation
{
public:
    MRTextAnnotation(int type);
    virtual void loadFromPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr) override;
    virtual void appendToPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr,
                              void *data = nullptr,
                              float *color = nullptr) override;
    void draw(QPainter &painter, float scaleX, float scaleY, float rotation) override;
};

#endif // MRTEXTANNOTATION_H
