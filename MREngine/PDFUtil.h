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
#include <QRectF>
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

PDFCORESHARED_EXPORT QRectF mapFromOrigin(const QRectF &rect, float scaleX, float scaleY, float rotation);

PDFCORESHARED_EXPORT fz_rect mapFromOrigin(const fz_rect &rect,
                                           float scaleX,
                                           float scaleY,
                                           float rotation);

PDFCORESHARED_EXPORT fz_point mapFromOrigin(fz_point &point,
                                            float scaleX,
                                            float scaleY,
                                            float rotation);


#endif /* PDFUTIL_H */

