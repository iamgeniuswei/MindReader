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
#include <QDebug>
class MRPagePrivate
{
public:
    MRPagePrivate(fz_context *ctx = nullptr, fz_document *doc = nullptr)
            :context(ctx), document(doc)
    {}
    ~MRPagePrivate()
    {
        if(page)
        {
            qDebug() <<"sizeof (fz_page): " << sizeof (fz_page);
            fz_try(context)
            {
                fz_drop_page(context, page);
            }
            fz_catch (context)
            {
                qDebug() << fz_caught_message (context);
            }
        }

    }
    
    void init();
    
public:
    fz_context *context = nullptr;
    fz_document *document = nullptr;
    fz_page *page = nullptr;
    fz_display_list *display_list;
    fz_stext_page *textPage = nullptr;
    int index = 0;
    int width = 0;
    int height = 0;
};

#endif /* PDFPAGE_P_H */

