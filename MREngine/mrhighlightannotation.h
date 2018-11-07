#ifndef MRHIGHLIGHTANNOTATION_H
#define MRHIGHLIGHTANNOTATION_H
#include "mrannotation.h"

class MRHighlightAnnotation : public MRAnnotation
{
public:
    MRHighlightAnnotation(int type);
    void draw(QPainter &painter, float scaleX, float scaleY, float rotation) override;
};

#endif // MRHIGHLIGHTANNOTATION_H
