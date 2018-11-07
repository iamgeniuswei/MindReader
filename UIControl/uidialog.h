#ifndef UIDIALOG_H
#define UIDIALOG_H

#include <QDialog>
#include "uicontrol_global.h"
class UICONTROLSHARED_EXPORT UIDialog : public QDialog
{
    Q_OBJECT
public:
    explicit UIDialog(QWidget *parent = nullptr);
protected:
    virtual void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // UIDIALOG_H
