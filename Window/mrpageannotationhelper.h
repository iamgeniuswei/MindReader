#ifndef MRPAGEANNOTATIONHELPER_H
#define MRPAGEANNOTATIONHELPER_H

#include <QPoint>
class MRPageAnnotationHelper
{
public:
    MRPageAnnotationHelper();
    static void appendAnnotationToPage(const QPoint& start,
                                  const QPoint& end,
                                  int type);
    static void appendLineToPage(const QPoint& start,
                                 const QPoint& end,
                                 int type);
};

#endif // MRPAGEANNOTATIONHELPER_H
