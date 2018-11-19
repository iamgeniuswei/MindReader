/********************************************************************************
** Form generated from reading UI file 'qimagetextwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QIMAGETEXTWIDGET_H
#define UI_QIMAGETEXTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QImageTextWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lbImage;
    QLabel *lbText;

    void setupUi(QWidget *QImageTextWidget)
    {
        if (QImageTextWidget->objectName().isEmpty())
            QImageTextWidget->setObjectName(QString::fromUtf8("QImageTextWidget"));
        QImageTextWidget->resize(197, 187);
        verticalLayout = new QVBoxLayout(QImageTextWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lbImage = new QLabel(QImageTextWidget);
        lbImage->setObjectName(QString::fromUtf8("lbImage"));
        lbImage->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbImage);

        lbText = new QLabel(QImageTextWidget);
        lbText->setObjectName(QString::fromUtf8("lbText"));
        lbText->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lbText);


        retranslateUi(QImageTextWidget);

        QMetaObject::connectSlotsByName(QImageTextWidget);
    } // setupUi

    void retranslateUi(QWidget *QImageTextWidget)
    {
        QImageTextWidget->setWindowTitle(QApplication::translate("QImageTextWidget", "Form", nullptr));
        lbImage->setText(QString());
        lbText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QImageTextWidget: public Ui_QImageTextWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIMAGETEXTWIDGET_H
