#ifndef MRLINEANNOTATION_H
#define MRLINEANNOTATION_H

#include "mrannotation.h"
class MRLineAnnotation : public MRAnnotation
{
public:
    MRLineAnnotation(int type);
    void draw(QPainter &painter, float scaleX, float scaleY, float rotation) override;
};

#endif // MRLINEANNOTATION_H
