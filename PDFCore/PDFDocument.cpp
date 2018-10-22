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

#include "PDFDocument.h"
#include "private/PDFDocument_p.h"
#include "PDFPage.h"

#include <mupdf/fitz.h>

#include <iostream>
PDFDocument::PDFDocument() 
    :d(new PDFDocumentPrivate)
{
}

PDFDocument::PDFDocument(const PDFDocument& orig) {
}

PDFDocument::~PDFDocument() {
    if(d)
        delete d;
}

bool PDFDocument::openDocument(const QString& file) {
    if(d)
    {
        d->context = fz_new_context(nullptr, nullptr, FZ_STORE_UNLIMITED);
        if(d->context)
        {
            fz_register_document_handlers(d->context);
        }
        
        fz_try(d->context)
        {
            d->document = fz_open_document(d->context, file.toUtf8().data());
            d->num_pages = fz_count_pages(d->context, d->document);
            for(int i=0; i<d->num_pages; i++)
            {
                PDFPage *page = new PDFPage(this, i);
                d->pages << page;
            }
        }
        fz_catch(d->context)
        {
            std::cerr << fz_caught_message(d->context) << std::endl;
            return false;
        }
    }
    return true;
}

fz_context* PDFDocument::context() const
{
    if(d)
        return d->context;
    return nullptr;
}

fz_document* PDFDocument::document() const
{
    if(d)
        return d->document;
    return nullptr;
}

/**
 * return a page in the document.
 * @param index
 * @return PDFPage*
 */
PDFPage* PDFDocument::page(int index) const
{
    PDFPage *page = nullptr;
    if(d)
    {
        page = d->pages.at(index);
    }
    return page;
}

int PDFDocument::pageCount() const
{
    int ret = -1;
    if(d)
    {
        ret = d->num_pages;
    }
    return ret;
}
