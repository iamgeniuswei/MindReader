#include "mrannotationcreator.h"
#include "mupdf/pdf.h"
#include "mrlineannotation.h"
#include "mrsquareannotation.h"
#include "mrtextannotation.h"
#include "mrhighlightannotation.h"
MRAnnotationCreator::MRAnnotationCreator()
{

}

std::shared_ptr<MRAnnotation> MRAnnotationCreator::createAnnotation(int type)
{
    switch (type)
    {
    case PDF_ANNOT_LINE:
        return std::make_shared<MRLineAnnotation>(PDF_ANNOT_LINE);
        break;
    case PDF_ANNOT_SQUARE:
        return std::make_shared<MRSquareAnnotation>(PDF_ANNOT_SQUARE);
        break;
    case PDF_ANNOT_TEXT:
        return std::make_shared<MRTextAnnotation>(PDF_ANNOT_TEXT);
        break;
    case PDF_ANNOT_HIGHLIGHT:
        return std::make_shared<MRHighlightAnnotation>(PDF_ANNOT_HIGHLIGHT);
        break;
    default:
        return nullptr;
    }
}
