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
#include <memory>
#include "pdfcore_global.h"
class MRDocumentPrivate;
class MRPage;
class PDFCORESHARED_EXPORT MRDocument {
public:
    MRDocument();
    MRDocument(const MRDocument& orig) = delete ;
    MRDocument& operator=(const MRDocument& orig) = delete;
    ~MRDocument();
public:
    bool openDocument(const QString &file);
    fz_context* context() const;
    fz_document* document() const;
    std::shared_ptr<MRPage> page(int index);
    int pageCount() const;
private:
    MRDocumentPrivate *d;

};

#endif /* PDFDOCUMENT_H */

