/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PDFPage_p.h
 * Author: develop
 *
 * Created on October 10, 2018, 11:25 AM
 */

#ifndef PDFPAGE_P_H
#define PDFPAGE_P_H
extern "C"{
#include <mupdf/fitz.h>
}
class PDFPagePrivate
{
public:
    PDFPagePrivate(fz_context *ctx = nullptr, fz_document *doc = nullptr)
            :context(ctx), document(doc)
    {}
    ~PDFPagePrivate()
    {
        if(page)
            fz_drop_page(context, page);
    }
    
    void init();
    
public:
    fz_context *context = nullptr;
    fz_document *document = nullptr;
    fz_page *page = nullptr;
    fz_display_list *display_list;
//    fz_text_sheet *text_sheet;
    fz_stext_page *textPage = nullptr;
    unsigned int index = 0;
};

#endif /* PDFPAGE_P_H */

