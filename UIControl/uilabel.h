#ifndef UILABEL_H
#define UILABEL_H

#include <QLabel>
#include "uicontrol_global.h"
class UICONTROLSHARED_EXPORT UILabel : public QLabel
{
    Q_OBJECT

public:
    UILabel(QWidget *parent = nullptr);    
signals:
    void clicked();
    void doubleClicked();
protected:
    virtual void mousePressEvent(QMouseEvent *ev) override;

    virtual void
    mouseDoubleClickEvent(QMouseEvent *event) override;

};

#endif
