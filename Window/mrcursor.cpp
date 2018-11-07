#include "mrcursor.h"
#include "mrarticlepagedisplayer.h"
MRCursor::MRCursor()
{

}

void MRCursor::setCursor(MRArticlePageDisplayer *widget, CURSOR cursor)
{
    Q_ASSERT ( widget != nullptr );
    switch (cursor)
    {
    case CURSOR::HAND:
    {
        widget->setCursor (Qt::OpenHandCursor);
        widget->setCursorType (cursor);
    }
        break;
    case CURSOR::SELECT:
    {
        widget->setCursor (Qt::ArrowCursor);
        widget->setCursorType (CURSOR::SELECT);
        widget->setAnnotationFlag (PDF_ANNOT_HIGHLIGHT);
    }
        break;
    case CURSOR::LINE:
    {
        widget->setCursor (Qt::CrossCursor);
        widget->setCursorType (CURSOR::LINE);
        widget->setAnnotationFlag (PDF_ANNOT_LINE);
    }
        break;
    case CURSOR::RECTANGLE:
    {
        widget->setCursor (Qt::CrossCursor);
        widget->setCursorType (CURSOR::RECTANGLE);
        widget->setAnnotationFlag (PDF_ANNOT_SQUARE);
    }
        break;
    case CURSOR::TEXT:
        widget->setCursor (Qt::IBeamCursor);
        break;
    default:
        widget->setCursor (Qt::OpenHandCursor);
        break;
    }
}
