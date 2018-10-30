#include "uiwidget.h"
#include <QStyleOption>
#include <QPainter>
UIWidget::UIWidget(QWidget *parent) : QWidget(parent)
{

}

void UIWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
