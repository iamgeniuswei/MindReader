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
#include "mrcontext.h"
MRDocument::MRDocument() 
    :d(new MRDocumentPrivate)
{
    MRContext *context = MRContext::instance ();
    d->context = context->context ();
}

MRDocument::~MRDocument() {    
    if(d)
        delete d;
}

bool MRDocument::openDocument(const QString& file)
{
    Q_ASSERT (d != nullptr );
    Q_ASSERT (d->context != nullptr );

        fz_try(d->context)
        {
            d->document = fz_open_document(d->context, file.toUtf8().data());            
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

        fz_try(d->context)
        {
            d->num_pages = fz_count_pages(d->context, d->document);
        }
        fz_catch (d->context)
        {
            fz_drop_document (d->context,
                              d->document);
            qDebug() << fz_caught_message (d->context);
            return false;
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
