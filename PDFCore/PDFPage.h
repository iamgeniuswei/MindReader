/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PDFPage.h
 * Author: develop
 *
 * Created on October 10, 2018, 11:21 AM
 */

#ifndef PDFPAGE_H
#define PDFPAGE_H
#include <QImage>
#include <QString>
#include "pdfcore_global.h"
class PDFDocument;
class PDFPagePrivate;
class PDFCORESHARED_EXPORT PDFPage {
public:
    PDFPage(PDFDocument *document = nullptr, int index =0, int xscale = 1, int yscale = 1, int rotation = 0);
    PDFPage(const PDFPage& orig);
    virtual ~PDFPage();
    QImage renderPage(float scaleX, float scaleY, float rotation);
    QString text(const QRectF& rect) const;
private:
    PDFPagePrivate *d;
};

#endif /* PDFPAGE_H */

