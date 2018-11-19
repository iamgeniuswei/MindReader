/********************************************************************************
** Form generated from reading UI file 'uitextwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UITEXTWIDGET_H
#define UI_UITEXTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UITextWidget
{
public:

    void setupUi(QWidget *UITextWidget)
    {
        if (UITextWidget->objectName().isEmpty())
            UITextWidget->setObjectName(QString::fromUtf8("UITextWidget"));
        UITextWidget->resize(400, 300);

        retranslateUi(UITextWidget);

        QMetaObject::connectSlotsByName(UITextWidget);
    } // setupUi

    void retranslateUi(QWidget *UITextWidget)
    {
        UITextWidget->setWindowTitle(QApplication::translate("UITextWidget", "UITextWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UITextWidget: public Ui_UITextWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UITEXTWIDGET_H
