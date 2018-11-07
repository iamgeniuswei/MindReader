#ifndef MRRECTANGLEANNOTATION_H
#define MRRECTANGLEANNOTATION_H

#include "mrannotation.h"
class MRSquareAnnotation : public MRAnnotation
{
public:
    MRSquareAnnotation(int type);
    void draw(QPainter &painter, float scaleX, float scaleY, float rotation) override;
};

#endif // MRRECTANGLEANNOTATION_H
