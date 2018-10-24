/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PDFUtil.h"
QRectF mapToOrigin(const QRectF &rect, float scaleX, float scaleY, float rotation)
{
    fz_matrix transform = fz_identity;
    fz_matrix inverse;
    fz_rect r;

    // build matrix
    transform = fz_rotate(rotation);
    transform = fz_pre_scale(transform, scaleX, scaleY);

    // invert matrix
    inverse = fz_invert_matrix(transform);

    // map
    r.x0 = rect.left();
    r.y0 = rect.top();
    r.x1 = rect.right();
    r.y1 = rect.bottom();
    r = fz_transform_rect(r, inverse);

    return QRectF(r.x0, r.y0, r.x1 - r.x0, r.y1 - r.y0);
}
QRectF mapFromOrigin(const QRectF &rect, float scaleX, float scaleY, float rotation)
{
    fz_matrix transform = fz_identity;
    fz_rect r;
    transform = fz_scale(scaleX, scaleY);
    fz_pre_rotate(transform, rotation);
    r.x0 = rect.left ();
    r.y0 = rect.top ();
    r.x1 = rect.right ();
    r.y1 = rect.bottom ();
    r = fz_transform_rect (r, transform);
    return QRectF(r.x0, r.y0, r.x1 - r.x0, r.y1 - r.y0);
}
