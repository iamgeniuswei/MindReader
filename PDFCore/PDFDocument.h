/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PDFDocument.h
 * Author: develop
 *
 * Created on October 10, 2018, 11:05 AM
 */

#ifndef PDFDOCUMENT_H
#define PDFDOCUMENT_H

#include <QString>
#include <mupdf/fitz.h>
#include "pdfcore_global.h"
class PDFDocumentPrivate;
class PDFPage;
class PDFCORESHARED_EXPORT PDFDocument {
public:
    PDFDocument();
    PDFDocument(const PDFDocument& orig);
    virtual ~PDFDocument();
    bool openDocument(const QString &file);
    fz_context* context() const;
    fz_document* document() const;
    PDFPage* page(int index) const;
    int pageCount() const;
private:
    PDFDocumentPrivate *d;

};

#endif /* PDFDOCUMENT_H */

