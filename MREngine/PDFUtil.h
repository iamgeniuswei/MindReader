/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PDFUtil.h
 * Author: develop
 *
 * Created on October 12, 2018, 8:31 AM
 */

#ifndef PDFUTIL_H
#define PDFUTIL_H
#include "mupdf/fitz.h"
#include "mupdf/pdf.h"
#include <QRectF>
#include <memory>
class MRAnnotation;
class MRLineAnnotation;
class MRSquareAnnotation;
class MRTextAnnotation;
class MRHighlightAnnotation;
#include "pdfcore_global.h"
PDFCORESHARED_EXPORT QRectF mapToOrigin(const QRectF &rect, float scaleX, float scaleY, float rotation);

PDFCORESHARED_EXPORT fz_rect mapToOrigin(fz_rect& rect,
                                         float scaleX,
                                         float scaleY,
                                         float rotation);

PDFCORESHARED_EXPORT fz_point mapToOrigin(fz_point &point,
                                          float scaleX,
                                          float scaleY,
                                          float rotation);
PDFCORESHARED_EXPORT fz_quad mapToOrigin(fz_quad &quad,
                                          float scaleX,
                                          float scaleY,
                                          float rotation);


PDFCORESHARED_EXPORT QRectF mapFromOrigin(const QRectF &rect, float scaleX, float scaleY, float rotation);

PDFCORESHARED_EXPORT fz_rect mapFromOrigin(const fz_rect &rect,
                                           float scaleX,
                                           float scaleY,
                                           float rotation);

PDFCORESHARED_EXPORT fz_point mapFromOrigin(fz_point &point,
                                            float scaleX,
                                            float scaleY,
                                            float rotation);
PDFCORESHARED_EXPORT fz_quad mapFromOrigin(fz_quad &quad,
                                            float scaleX,
                                            float scaleY,
                                            float rotation);

using SPtrMRA = std::shared_ptr<MRAnnotation>;
using SPtrMRLA = std::shared_ptr<MRLineAnnotation>;
using SPtrMRSA = std::shared_ptr<MRSquareAnnotation>;
using SPtrMRTA = std::shared_ptr<MRTextAnnotation>;
using SPtrMRHA = std::shared_ptr<MRHighlightAnnotation>;
#endif /* PDFUTIL_H */

