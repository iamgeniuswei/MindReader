#ifndef MRHIGHLIGHTANNOTATION_H
#define MRHIGHLIGHTANNOTATION_H
#include "mrannotation.h"

class MRHighlightAnnotation : public MRAnnotation
{
public:
    MRHighlightAnnotation(int type);
    virtual void loadFromPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr) override;
    virtual void appendToPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr,
                              void *data = nullptr,
                              float *scolor = nullptr) override;
    void draw(QPainter &painter, float scaleX, float scaleY, float rotation) override;

private:
    fz_quad quad{{0,0}, {0,0}, {0,0}, {0,0}};
};

#endif // MRHIGHLIGHTANNOTATION_H
