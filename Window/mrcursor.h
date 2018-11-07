#ifndef MRCURSOR_H
#define MRCURSOR_H
#include "mrwindowutility.h"
class MRArticlePageDisplayer;
class MRCursor
{
public:
    MRCursor();
    static void setCursor(MRArticlePageDisplayer *widget,
                          CURSOR cursor);
};

#endif // MRCURSOR_H
