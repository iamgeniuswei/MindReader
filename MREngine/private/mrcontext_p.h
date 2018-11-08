#ifndef MRCONTEXT_P_H
#define MRCONTEXT_P_H
#include <mupdf/fitz.h>
class MRContextPrivate
{
public:
    MRContextPrivate(){}
    ~MRContextPrivate()
    {
        if(context)
        {
            fz_drop_context (context);
        }
    }

public:
    fz_context *context = nullptr;
    volatile bool isLoaded = false;
};
#endif // MRCONTEXT_P_H
