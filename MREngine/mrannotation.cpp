#include "mrannotation.h"

MRAnnotation::MRAnnotation(int flag)
    :type(flag)
{

}

int MRAnnotation::getType() const
{
    return type;
}

void MRAnnotation::setType(int value)
{
    type = value;
}

//fz_rect MRAnnotation::getRect() const
//{
//    return rect;
//}

//void MRAnnotation::setRect(const fz_rect &value)
//{
//    rect = value;
//}

//const char *MRAnnotation::getContent() const
//{
//    return content;
//}

//void MRAnnotation::setContent(const char *value)
//{
//    content = value;
//}

//fz_point MRAnnotation::getStart() const
//{
//    return start;
//}

//void MRAnnotation::setStart(const fz_point &value)
//{
//    start = value;
//}

//fz_point MRAnnotation::getEnd() const
//{
//    return end;
//}

//void MRAnnotation::setEnd(const fz_point &value)
//{
//    end = value;
//}

//void MRAnnotation::setQuad(const fz_quad &value)
//{
//    quad = value;
//}
