#ifndef MRLINEANNOTATION_H
#define MRLINEANNOTATION_H

#include "mrannotation.h"
class MRLineAnnotation : public MRAnnotation
{
public:
    MRLineAnnotation(int type);
    virtual void loadFromPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr) override;
    virtual void appendToPage(fz_context *ctx = nullptr,
                              pdf_annot *annot = nullptr,
                              void *data = nullptr,
                              float *scolor = nullptr) override;
    virtual void draw(QPainter &painter, float scaleX, float scaleY, float rotation) override;
private:
    fz_point start{0, 0}, end{0, 0};
};

#endif // MRLINEANNOTATION_H
