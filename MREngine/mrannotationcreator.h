#ifndef MRANNOTATIONCREATOR_H
#define MRANNOTATIONCREATOR_H

class MRAnnotation;
#include <memory>
#include "pdfcore_global.h"
class PDFCORESHARED_EXPORT MRAnnotationCreator
{
public:
    MRAnnotationCreator();
    static std::shared_ptr<MRAnnotation> createAnnotation(int type);
};

#endif // MRANNOTATIONCREATOR_H
