/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PDFPage.cpp
 * Author: develop
 * 
 * Created on October 10, 2018, 11:21 AM
 */

#include "PDFPage.h"
#include "private/PDFPage_p.h"
#include "PDFDocument.h"
#include "mupdf/fitz.h"
#include <iostream>
#include <QRect>
#include <QPointF>

static inline void imageCleanupHandler(void *data)
{
    unsigned char *samples = static_cast<unsigned char *> (data);

    if (samples)
    {
        delete []samples;
    }
}

PDFPage::PDFPage(PDFDocument *document, int index, int xscale, int yscale, int rotation)
: d(new PDFPagePrivate(document->context(), document->document()))
{
    //load page
    d->page = fz_load_page(d->context, d->document, index);
    d->index = index;

    //create transform and bounds
    fz_matrix transform = fz_rotate(rotation);
    fz_pre_scale(transform, xscale, yscale);
    fz_rect bounds;
    bounds = fz_bound_page(d->context, d->page);
    fz_transform_rect(bounds, transform);
    
    //run display list
    fz_device *list_device;
    fz_display_list *display_list = fz_new_display_list(d->context, bounds);
    list_device = fz_new_list_device(d->context, display_list);
    fz_run_page(d->context, d->page, list_device, transform, NULL);
    fz_close_device(d->context, list_device);

    //run text page
    d->textPage = fz_new_stext_page(d->context, bounds);
    fz_device* text_device = fz_new_stext_device(d->context, d->textPage, nullptr);
    fz_run_display_list(d->context, display_list, text_device, transform, bounds, NULL);
    fz_close_device(d->context, text_device);
}

PDFPage::PDFPage(const PDFPage& orig)
{
}

PDFPage::~PDFPage()
{
}

QImage PDFPage::renderPage(float scaleX, float scaleY, float rotation)
{
    if (d)
    {

        fz_try(d->context)
        {

            fz_matrix transform = fz_identity;
            transform = fz_scale(scaleX, scaleY);
            fz_pre_rotate(transform, rotation);
            fz_pixmap *pix = fz_new_pixmap_from_page_number (d->context,
                                                             d->document,
                                                             d->index,
                                                             transform,
                                                             fz_device_rgb (d->context), 0);
            int width = fz_pixmap_width(d->context, pix);
            int height = fz_pixmap_height(d->context, pix);
//            int size = width * height * 4;
//            unsigned char *copyed_samples = new unsigned char[size];
            unsigned char *samles = pix->samples;
            QImage image(samles, width, height,pix->stride,QImage::Format_RGB888);
            return  image;
        }

        fz_catch(d->context)
        {

        }
    }
    return QImage();

}

void PDFPagePrivate::init()
{

}

QString PDFPage::text(const QRectF& rect) const
{
    QString ret;
    fz_rect r;
    fz_point top_left;
    fz_point bottom_right;
    char *str;

    // build fz_rect
    top_left.x = r.x0 = rect.left();
    top_left.y = r.y0 = rect.top();
    bottom_right.x = r.x1 = rect.right();
    bottom_right.y = r.y1 = rect.bottom();

    std::cerr << d->context << std::endl;
    std::cerr << d->textPage << std::endl;
    // get text

    fz_try(d->context)
    {
        if (!fz_is_infinite_rect(r))
        {
            str = fz_copy_selection(d->context, d->textPage, top_left, bottom_right, 1);
            ret = QString::fromUtf8(str);
            free(str);
        }
    }

    fz_catch(d->context)
    {
        std::cerr << fz_caught_message(d->context);
    }


    return ret;
}
