#ifndef MRRECTANGLEANNOTATION_H
#define MRRECTANGLEANNOTATION_H

#include "mrannotation.h"
class MRSquareAnnotation : public MRAnnotation
{
public:
    MRSquareAnnotation(int type);
    virtual void loadFromPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr) override;
    virtual void appendToPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr,
                              void *data = nullptr,
                              float *scolor = nullptr) override;
    void draw(QPainter &painter, float scaleX, float scaleY, float rotation) override;
private:
    fz_rect rect{0, 0, 0, };
};

#endif // MRRECTANGLEANNOTATION_H
