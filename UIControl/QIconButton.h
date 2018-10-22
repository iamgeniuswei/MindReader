/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QIconButton.h
 * Author: develop
 *
 * Created on October 15, 2018, 3:30 PM
 */

#ifndef QICONBUTTON_H
#define QICONBUTTON_H
#include <QPushButton>

#include "private/QIconButton_p.h"
class QIconButtonPrivate;

class QIconButton : public QPushButton {
public:
    QIconButton(QWidget *parent = nullptr, QString prefix = QString());
    //    QIconButton(const QIconButton& orig);
    virtual ~QIconButton();

    enum BUTTONSTATUS {
        NORMAL, ENTER, LEAVE, PRESS, RELEASE, DISABLE
    };


    void setIconPath(const QString& prefix, qreal scale = 1.0);
protected:
    void setButtonStatus(BUTTONSTATUS status);

protected:
    void paintEvent(QPaintEvent* e) override;
    void enterEvent(QEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
private:
    QIconButtonPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(QIconButton)

};

#endif /* QICONBUTTON_H */

