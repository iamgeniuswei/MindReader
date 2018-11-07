/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PDFDocument_p.h
 * Author: develop
 *
 * Created on October 10, 2018, 11:06 AM
 */

#ifndef PDFDOCUMENT_P_H
#define PDFDOCUMENT_P_H
extern "C"{
#include <mupdf/fitz.h>
}
#include <QList>
#include <QDebug>
#include <memory>
class MRPage;
class MRDocumentPrivate
{
public:
    MRDocumentPrivate(){}
    ~MRDocumentPrivate()
    {
        while (!pages.empty()) 
        {
             std::shared_ptr<MRPage> page = pages.front();
             pages.pop_front();
        }

        if(document)
        {
            fz_try(context)
            {
                fz_drop_document(context, document);
            }
            fz_catch (context)
            {
                qDebug() << fz_caught_message (context);
            }

        }
        if(context)
        {
            fz_drop_context (context);
        }
    }
    
public:
    fz_context *context = nullptr;
    fz_document *document = nullptr;
    bool transparent = false;
    int r = 0, g = 0, b = 0, a = 255;
    QList<std::shared_ptr<MRPage>> pages;
    int num_pages = 0;
    
private:
    void deleteData();
    
};

#endif /* PDFDOCUMENT_P_H */

