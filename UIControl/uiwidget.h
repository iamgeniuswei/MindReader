#ifndef UIWIDGET_H
#define UIWIDGET_H

#include <QWidget>
#include "uicontrol_global.h"
class UICONTROLSHARED_EXPORT UIWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UIWidget(QWidget *parent = nullptr);

protected:
    virtual void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // UIWIDGET_H
