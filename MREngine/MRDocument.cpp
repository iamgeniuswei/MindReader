/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PDFDocument.cpp
 * Author: develop
 * 
 * Created on October 10, 2018, 11:05 AM
 */

#include "mrdocument.h"
#include "private/mrdocument_p.h"
#include "mrpage.h"

#include <mupdf/fitz.h>

#include <iostream>
#include <QDebug>
MRDocument::MRDocument() 
    :d(new MRDocumentPrivate)
{
}

MRDocument::MRDocument(const MRDocument& orig) {
}

MRDocument::~MRDocument() {    
    if(d)
        delete d;
}

void lock_mutex(void *user, int lock)
{

}

void unlock_mutex(void *user, int lock)
{

}


bool MRDocument::openDocument(const QString& file)
{
    Q_ASSERT (d);
    fz_locks_context lock;
    int mutex[5];
    lock.user = mutex;
    lock.lock = lock_mutex ;
    lock.unlock = unlock_mutex;
    if(d)
    {
        d->context = fz_new_context(nullptr, &lock, FZ_STORE_UNLIMITED);
        if(d->context)
        {
            fz_register_document_handlers(d->context);
        }

        fz_try(d->context)
        {
            d->document = fz_open_document(d->context, file.toUtf8().data());
            d->num_pages = fz_count_pages(d->context, d->document);
//            for(int i=0; i<d->num_pages; i++)
//            {
//                std::shared_ptr<MRPage> page = std::make_shared<MRPage>(this, i);
//                d->pages << page;
//            }
        }
        fz_catch(d->context)
        {
            qDebug() << fz_caught_message (d->context);
            return false;
        }
    }

    return true;
}

fz_context* MRDocument::context() const
{
    Q_ASSERT (d);
    if(d)
        return d->context;
    return nullptr;
}

fz_document* MRDocument::document() const
{
    Q_ASSERT(d);
    if(d)
        return d->document;
    return nullptr;
}

/**
 * return a page in the document.
 * @param index
 * @return PDFPage*
 */
std::shared_ptr<MRPage> MRDocument::page(int index)
{
    Q_ASSERT(d);
    std::shared_ptr<MRPage> page = nullptr;
//    if(d)
//    {
//        page = d->pages.at(index);
//    }
    page = std::make_shared<MRPage>(this, index);
    return page;
}

int MRDocument::pageCount() const
{
    Q_ASSERT (d);
    int ret = -1;
    if(d)
    {
        ret = d->num_pages;
    }
    return ret;
}
