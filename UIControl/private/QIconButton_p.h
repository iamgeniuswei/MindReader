/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QIconButton_p.h
 * Author: develop
 *
 * Created on October 15, 2018, 3:36 PM
 */

#ifndef QICONBUTTON_P_H
#define QICONBUTTON_P_H
#include <QObject>

class QIconButton;
class QIconButtonPrivate
{
    Q_DECLARE_PUBLIC(QIconButton)
public:
    QIconButtonPrivate(QIconButton *parent)
    :q_ptr(parent)
    {}
    
public:
    QPixmap current_icon;
    QList<QPixmap> icons;
    int icons_count = 4;
private:
    QIconButton *const q_ptr;
};


#endif /* QICONBUTTON_P_H */

