/********************************************************************************
** Form generated from reading UI file 'mrarticleitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRARTICLEITEM_H
#define UI_MRARTICLEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MRArticleItem
{
public:
    QLabel *MRAITitle;
    QLabel *MRAIProgress;

    void setupUi(QWidget *MRArticleItem)
    {
        if (MRArticleItem->objectName().isEmpty())
            MRArticleItem->setObjectName(QString::fromUtf8("MRArticleItem"));
        MRArticleItem->resize(120, 180);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MRArticleItem->sizePolicy().hasHeightForWidth());
        MRArticleItem->setSizePolicy(sizePolicy);
        MRAITitle = new QLabel(MRArticleItem);
        MRAITitle->setObjectName(QString::fromUtf8("MRAITitle"));
        MRAITitle->setGeometry(QRect(30, 70, 54, 12));
        MRAITitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        MRAIProgress = new QLabel(MRArticleItem);
        MRAIProgress->setObjectName(QString::fromUtf8("MRAIProgress"));
        MRAIProgress->setGeometry(QRect(80, 8, 32, 16));
        MRAIProgress->setAlignment(Qt::AlignCenter);

        retranslateUi(MRArticleItem);

        QMetaObject::connectSlotsByName(MRArticleItem);
    } // setupUi

    void retranslateUi(QWidget *MRArticleItem)
    {
        MRArticleItem->setWindowTitle(QApplication::translate("MRArticleItem", "Form", nullptr));
        MRAITitle->setText(QString());
        MRAIProgress->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MRArticleItem: public Ui_MRArticleItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRARTICLEITEM_H
