#include "mrcontext.h"
#include "private/mrcontext_p.h"
#include <QObject>
#include <QDebug>
MRContext *MRContext::_instance = nullptr;
MRContext::MRContextGarbo MRContext::_Garbo;
std::mutex MRContext::lock;
void lock_mutex(void *user, int lock)
{
    Q_UNUSED (user);
    Q_UNUSED (lock);
}

void unlock_mutex(void *user, int lock)
{
    Q_UNUSED (user);
    Q_UNUSED (lock);
}


MRContext::~MRContext()
{
    delete d;
}

MRContext *MRContext::instance()
{
    if(_instance == nullptr)
    {
        std::lock_guard<std::mutex> lk(lock);
        if(_instance == nullptr)
        {
            _instance = new MRContext();
        }
    }
    return _instance;
}

fz_context *MRContext::context()
{
    Q_ASSERT (d != nullptr );
    Q_ASSERT (d->context != nullptr );
    return d->context;
}

void MRContext::loadContext()
{
    Q_ASSERT (d != nullptr );
    fz_locks_context lock;
    int mutex[5];
    lock.user = mutex;
    lock.lock = lock_mutex ;
    lock.unlock = unlock_mutex;
    if(d)
    {
        d->context = fz_new_context(nullptr, &lock, 50<<20);
        if(d->context)
        {
            fz_try(d->context)
            {
                fz_register_document_handlers(d->context);
                d->isLoaded = true;
            }
            fz_catch (d->context)
            {
                qDebug()<< fz_caught_message (d->context);
                fz_drop_context (d->context);
                d->context = nullptr;
            }
        }
    }
}

MRContext::MRContext()
    :d(new MRContextPrivate)
{
    loadContext ();
}
