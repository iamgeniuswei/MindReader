#include "uilabel.h"
#include <QMouseEvent>
UILabel::UILabel(QWidget *parent) :
    QLabel(parent)
{
}

void UILabel::mousePressEvent(QMouseEvent *ev)
{
    emit clicked ();
}

void UILabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit doubleClicked ();
//    QLabel::mouseDoubleClickEvent (event);
}
