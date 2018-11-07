#include "uidialog.h"
#include <QStyleOption>
#include <QPainter>
UIDialog::UIDialog(QWidget *parent) : QDialog(parent)
{

}

void UIDialog::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
