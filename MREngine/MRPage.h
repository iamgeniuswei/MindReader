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
#include "mupdf/fitz.h"
#include "mupdf/pdf.h"
#include "mrannotation.h"
#include <memory>
class MRDocument;
class MRPagePrivate;
using SPtrMRA = std::shared_ptr<MRAnnotation>;
class PDFCORESHARED_EXPORT MRPage
{
public:
    MRPage(MRDocument *document = nullptr, int index =0, int xscale = 1, int yscale = 1, int rotation = 0);
    virtual ~MRPage();
    QImage renderPage(float scaleX, float scaleY, float rotation);
    QString text(const QRectF& rect) const;
    QString getSelectionText(const fz_rect& rect);
    void getSelectionQuads(const fz_rect& rect, fz_quad *quads, int& num);
    fz_context* context() const;
    fz_document* document() const;
    fz_page* page() const;
	QSizeF size() const;
    void addAnnotation(int type,
                       const fz_rect &rect,
                       const fz_point &start,
                       const fz_point &end,
                       const fz_quad &quad,
                       const char* content);
    SPtrMRA addAnnotation(int type, void *data, float *color);
    void addAnnotation(const MRAnnotation &annot);
    void addAnnotation(std::shared_ptr<MRAnnotation> &annot);
    void getAnnotations(QList<std::shared_ptr<MRAnnotation> > &annotations);
    QList<SPtrMRA> getAnnotations();

private:
    MRPagePrivate *d;
};

#endif /* PDFPAGE_H */

