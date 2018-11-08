#ifndef MRCONTEXT_H
#define MRCONTEXT_H
#include <memory>
#include <mutex>
#include <condition_variable>
#include "mupdf/fitz.h"
class MRContextPrivate;
class MRContext
{
public:
    virtual ~MRContext();
    static MRContext *instance();
    fz_context* context();
private:
    void loadContext();
    MRContextPrivate *d = nullptr;
    static std::mutex lock;
private:
    explicit MRContext();
    MRContext(const MRContext& orig) = delete;
    MRContext& operator=(const MRContext&) = delete;
    MRContext(MRContext &&) = delete;
    static MRContext *_instance;
    class MRContextGarbo
    {
    public:
        ~MRContextGarbo()
        {
            if(_instance != nullptr)
            {
                delete _instance;
                _instance = nullptr;
            }
        }
    };
    static MRContextGarbo _Garbo;
};

#endif // MRCONTEXT_H
