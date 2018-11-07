#ifndef MRTEXTANNOTATION_H
#define MRTEXTANNOTATION_H

#include "mrannotation.h"
class MRTextAnnotation : public MRAnnotation
{
public:
    MRTextAnnotation(int type);
    void draw(QPainter &painter, float scaleX, float scaleY, float rotation) override;
};

#endif // MRTEXTANNOTATION_H
