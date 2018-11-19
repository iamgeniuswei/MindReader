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

#include "mrpage.h"
#include "private/mrpage_p.h"
#include "mrdocument.h"
#include "mupdf/fitz.h"
#include <iostream>
#include <QRect>
#include <QPointF>
#include <QDebug>
#include "mrannotationcreator.h"
#include <mutex>
static inline void imageCleanupHandler(void *data)
{
    unsigned char *samples = static_cast<unsigned char *> (data);

    if (samples)
    {
        delete []samples;
    }
}

MRPage::MRPage(MRDocument *document, int index, int xscale, int yscale, int rotation)
: d(new MRPagePrivate(document->context(), document->document()))
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


MRPage::~MRPage()
{
    qDebug() <<"sizeof (MRPage): " << sizeof (MRPage);
    if(d)
        delete d;
}
std::mutex page_lock;
std::lock_guard<std::mutex> lk(page_lock);
QImage MRPage::renderPage(float scaleX, float scaleY, float rotation)
{

    int width = 0, height = 0;
    fz_pixmap *pix = nullptr;
    unsigned char* copyed_samples = nullptr;


    fz_rect rect;
    fz_irect bbox;
//    fz_pixmap *pix = nullptr;
    fz_device *dev = NULL;

    int alpha = 0;
    fz_var(dev);
    fz_context *ctx = fz_clone_context (d->context);

    fz_try(ctx)
    {
        fz_matrix transform = fz_identity;
        transform = fz_scale(scaleX, scaleY);
        fz_pre_rotate(transform, rotation);
        rect = fz_bound_page(ctx, d->page);
        rect = fz_transform_rect(rect, transform);
        bbox = fz_round_rect(rect);

        pix = fz_new_pixmap_with_bbox(ctx, fz_device_rgb (d->context), bbox, 0, alpha);

        if (alpha)
            fz_clear_pixmap(ctx, pix);
        else
            fz_clear_pixmap_with_value(ctx, pix, 0xFF);

        dev = fz_new_draw_device(ctx, transform, pix);

        fz_enable_device_hints(ctx, dev, FZ_NO_CACHE);
        fz_run_page(ctx, d->page, dev, fz_identity, NULL);
        fz_close_device(ctx, dev);
    }
    fz_always(ctx)
    {
        fz_drop_device(ctx, dev);
    }
    fz_catch(ctx)
    {
        fz_drop_pixmap(ctx, pix);
        fz_rethrow(ctx);
    }

//	return pix;
    d->width = width = fz_pixmap_width(ctx, pix);
    d->height = height = fz_pixmap_height(ctx, pix);
    unsigned int size = pix->stride * height;
    copyed_samples = new unsigned char[size];
    memcpy (copyed_samples, pix->samples, size);
    QImage image(copyed_samples,
                 width, height,pix->stride,
                 QImage::Format_RGB888,
                 imageCleanupHandler,
                 copyed_samples);
    fz_drop_pixmap (ctx, pix);
    fz_drop_context (ctx);
    return  image;


//    if (d)
//    {
//        fz_context *ctx = fz_clone_context (d->context);
//        fz_try(ctx)
//        {

//            fz_matrix transform = fz_identity;
//            transform = fz_scale(scaleX, scaleY);
//            fz_pre_rotate(transform, rotation);
//            pix = fz_new_pixmap_from_page_number (ctx,
//                                                             d->document,
//                                                             d->index,
//                                                             transform,
//                                                             fz_device_rgb (d->context), 0);
//            width = fz_pixmap_width(ctx, pix);
//            height = fz_pixmap_height(ctx, pix);
//            unsigned int size = pix->stride * height;
//            copyed_samples = new unsigned char[size];
//            memcpy (copyed_samples, pix->samples, size);
//        }
//        fz_catch(ctx)
//        {
//            qDebug() <<fz_caught_message (ctx);
//        }

//        QImage image(copyed_samples,
//                     width, height,pix->stride,
//                     QImage::Format_RGB888,
//                     imageCleanupHandler,
//                     copyed_samples);
//        fz_drop_pixmap (ctx, pix);
//        fz_drop_context (ctx);
//        return  image;
//    }
    return QImage();

}

void MRPagePrivate::init()
{

}

QString MRPage::text(const QRectF& rect) const
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
            fz_quad quads[4800];
            int num = fz_highlight_selection (d->context,
                                              d->textPage,
                                              top_left,
                                              bottom_right,
                                              quads,
                                              4800);
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

QString MRPage::getSelectionText(const fz_rect &rect)
{
    QString ret;
    fz_point top_left{rect.x0, rect.y0};
    fz_point bottom_right{rect.x1, rect.y1};
    char *str = nullptr;

    // get text
    fz_try(d->context)
    {
        if (!fz_is_infinite_rect(rect))
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

void MRPage::getSelectionQuads(const fz_rect &rect, fz_quad *quads, int &num)
{
    fz_point top_left{rect.x0, rect.y0};
    fz_point bottom_right{rect.x1, rect.y1};

    fz_try(d->context)
    {
        if (!fz_is_infinite_rect(rect))
        {
            num = fz_highlight_selection (d->context,
                                              d->textPage,
                                              top_left,
                                              bottom_right,
                                              quads,
                                              200);
        }
    }

    fz_catch(d->context)
    {
        std::cerr << fz_caught_message(d->context);
        num = 0;
    }
}

fz_context *MRPage::context() const
{
    return d->context;
}

fz_document *MRPage::document() const
{
    return d->document;
}

fz_page *MRPage::page() const
{
    return d->page;
}


QSizeF MRPage::size() const
{
	fz_rect rect;
	rect = fz_bound_page(d->context, d->page);
	return QSizeF(rect.x1 - rect.x0, rect.y1 - rect.y0);
}

void MRPage::addAnnotation(int type, const fz_rect& rect, const fz_point &start, const fz_point &end, const fz_quad &quad, const char *content)
{
    Q_ASSERT (d->context);
    Q_ASSERT (d->document);
    Q_ASSERT (d->page);

    pdf_page *page = reinterpret_cast<pdf_page*>(d->page);
    pdf_annot *annot = nullptr;
    Q_ASSERT (page);
    fz_try(d->context)
    {
        annot = pdf_create_annot(d->context,
                                            page,
                                           (enum pdf_annot_type) type);
    }
    fz_catch (d->context)
    {
        qDebug() << fz_caught_message (d->context);
        return;
    }
    MRAnnotationCreator::appendAnnotation (type,
                                           d->context,
                                           annot,
                                           rect,
                                           start,
                                           end,
                                           quad,
                                           content);
}

SPtrMRA MRPage::addAnnotation(int type, void *data, float *color)
{
    Q_ASSERT (d->context);
    Q_ASSERT (d->document);
    Q_ASSERT (d->page);

    pdf_page *page = reinterpret_cast<pdf_page*>(d->page);
    pdf_annot *annot = nullptr;
    Q_ASSERT (page);
    fz_try(d->context)
    {
        annot = pdf_create_annot(d->context,
                                            page,
                                           (enum pdf_annot_type) type);
    }
    fz_catch (d->context)
    {
        qDebug() << fz_caught_message (d->context);
        return nullptr;
    }
    SPtrMRA annotaion = MRAnnotationCreator::createAnnotation (type);
    annotaion->appendToPage (d->context, annot, data, color);
    return annotaion;
}

void MRPage::addAnnotation(const MRAnnotation &annot)
{
//    addAnnotation (annot.type,
//                   annot.rect,
//                   annot.content);
}

void MRPage::addAnnotation(std::shared_ptr<MRAnnotation> &annot)
{
//    Q_ASSERT ( annot != nullptr );
//    addAnnotation (annot->type,
//                   annot->rect,
//                   annot->start,
//                   annot->end,
//                   annot->quad,
//                   annot->content);
}

void MRPage::getAnnotations(QList<std::shared_ptr<MRAnnotation>> &annotations)
{
    Q_ASSERT (d->context);
    Q_ASSERT (d->page);
    fz_annot *annot = fz_first_annot (d->context, d->page);
    while (annot != nullptr)
    {
        pdf_annot* p_annot = reinterpret_cast<pdf_annot*>(annot);
        Q_ASSERT (p_annot);
        int type = pdf_annot_type (d->context,
                                           p_annot);
        SPtrMRA&& annotation = MRAnnotationCreator::loadAnnotation (type,
                                                                    d->context,
                                                                    p_annot);
        if(annotation != nullptr)
            annotations.append (std::move(annotation));
        annot = fz_next_annot (d->context,
                               annot);
    }
}

QList<SPtrMRA> MRPage::getAnnotations()
{
    QList<SPtrMRA> annotations;
    Q_ASSERT (d->context);
    Q_ASSERT (d->page);
    fz_annot *annot = nullptr;
    fz_try(d->context)
    {
        annot = fz_first_annot (d->context, d->page);
    }
    fz_catch (d->context)
    {
        qDebug() << fz_caught_message (d->context);
        annot = nullptr;
    }

    while (annot != nullptr)
    {        
        pdf_annot* p_annot = reinterpret_cast<pdf_annot*>(annot);
        Q_ASSERT (p_annot);
        fz_try(d->context)
        {
            int type = pdf_annot_type (d->context,
                                               p_annot);
            SPtrMRA&& annotation = MRAnnotationCreator::createAnnotation (type);
            if(annotation != nullptr)
            {
                annotation->loadFromPage (d->context, p_annot);
                annotations.append (std::move(annotation));
            }
            annot = fz_next_annot (d->context,
                                   annot);
        }
        fz_catch (d->context)
        {
            qDebug() << fz_caught_message (d->context);
            annot = nullptr;
        }
    }
    return annotations;
}
