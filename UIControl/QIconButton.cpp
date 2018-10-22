/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   QIconButton.cpp
 * Author: develop
 * 
 * Created on October 15, 2018, 3:30 PM
 */

#include "QIconButton.h"
#include "private/QIconButton_p.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
QIconButton::QIconButton(QWidget *parent, QString prefix)
: QPushButton(parent), d_ptr(new (std::nothrow) QIconButtonPrivate(this))
{

}

QIconButton::~QIconButton()
{

}



void QIconButton::setIconPath(const QString& prefix, qreal scale)
{
    Q_D(QIconButton);

    if (d != nullptr)
    {
        d->icons.clear();
        QStringList suffix_list = {"_normal", "_enter", "_press", "_disable"};

        for (int i = 0; i < suffix_list.size(); i++)
        {
            QString path_normal = prefix + suffix_list.at(i);
            qDebug() << path_normal;
            QPixmap pix_normal(path_normal);
            d->icons.append(pix_normal);
        }

        if (d->icons.size() == suffix_list.size())
        {
            d->current_icon = d->icons.at(0);
            qDebug() << d->current_icon.size();
            setFixedSize(d->current_icon.width()*scale, d->current_icon.height()*scale);
        }
    }
}

void QIconButton::setButtonStatus(BUTTONSTATUS status)
{
    Q_D(QIconButton);
    if (nullptr != d)
    {
        if (isEnabled() && d->icons.size() == d->icons_count)
        {
            switch (status)
            {
                case NORMAL:
                    d->current_icon = d->icons.at(0);
                    break;
                case ENTER:
                    d->current_icon = d->icons.at(1);
                    break;
                case LEAVE:
                    d->current_icon = d->icons.at(0);
                    break;
                case PRESS:
                    d->current_icon = d->icons.at(2);
                    break;
                case RELEASE:
                    d->current_icon = d->icons.at(0);
                    break;
                case DISABLE:
                    d->current_icon = d->icons.at(3);
                    break;
                default:
                    break;
            }
        }
    }
    update();
}

void QIconButton::paintEvent(QPaintEvent* e)
{
    Q_D(QIconButton);
    Q_UNUSED(e);
    if (d != nullptr)
    {
        QPainter painter(this);
        painter.drawPixmap(rect(), d->current_icon);
    }
}

void QIconButton::enterEvent(QEvent* event)
{
    setButtonStatus(ENTER);
}

void QIconButton::leaveEvent(QEvent* event)
{
    setButtonStatus(LEAVE);
}

void QIconButton::mousePressEvent(QMouseEvent* event)
{
    if (event->button() != Qt::LeftButton)
    {
        event->ignore();
        return;
    }
    if (hitButton(event->pos()))
    {
        setButtonStatus(PRESS);
        setDown(true);
        event->accept();
    } else
    {
        event->ignore();
    }
}

void QIconButton::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() != Qt::LeftButton)
    {
        event->ignore();
        return;
    }
    if(!isDown())
    {
        event->ignore();
        return;
    }
    if(rect().contains(event->pos()))
    {
        setDown(false);
        if(this->isEnabled())
        {
            emit clicked();
        }
        if(rect().contains(event->pos()) && isDown())
        {
            setButtonStatus(ENTER);
        }
        else
        {
            setButtonStatus(NORMAL);
        }
        event->accept();
    }
    else
    {
        setButtonStatus(LEAVE);
        event->ignore();
    }
}





//QIconButton::QIconButton(const QIconButton& orig)
//{
//
//}
//
//QIconButton::~QIconButton()
//{
//}

