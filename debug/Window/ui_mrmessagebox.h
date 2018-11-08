/********************************************************************************
** Form generated from reading UI file 'mrmessagebox.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRMESSAGEBOX_H
#define UI_MRMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MRMessageBox
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *MRMBClose;
    QHBoxLayout *horizontalLayout_2;
    QLabel *MRMBIcon;
    QVBoxLayout *verticalLayout;
    QLabel *MRMBText;
    QLabel *MRMBDetail;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *MRMessageBox)
    {
        if (MRMessageBox->objectName().isEmpty())
            MRMessageBox->setObjectName(QString::fromUtf8("MRMessageBox"));
        MRMessageBox->resize(367, 194);
        verticalLayout_2 = new QVBoxLayout(MRMessageBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MRMessageBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        MRMBClose = new QPushButton(MRMessageBox);
        MRMBClose->setObjectName(QString::fromUtf8("MRMBClose"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/close"), QSize(), QIcon::Normal, QIcon::Off);
        MRMBClose->setIcon(icon);
        MRMBClose->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(MRMBClose);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        MRMBIcon = new QLabel(MRMessageBox);
        MRMBIcon->setObjectName(QString::fromUtf8("MRMBIcon"));

        horizontalLayout_2->addWidget(MRMBIcon);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MRMBText = new QLabel(MRMessageBox);
        MRMBText->setObjectName(QString::fromUtf8("MRMBText"));
        MRMBText->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(MRMBText);

        MRMBDetail = new QLabel(MRMessageBox);
        MRMBDetail->setObjectName(QString::fromUtf8("MRMBDetail"));
        MRMBDetail->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(MRMBDetail);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        buttonBox = new QDialogButtonBox(MRMessageBox);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(1, 1);

        retranslateUi(MRMessageBox);

        QMetaObject::connectSlotsByName(MRMessageBox);
    } // setupUi

    void retranslateUi(QWidget *MRMessageBox)
    {
        MRMessageBox->setWindowTitle(QApplication::translate("MRMessageBox", "Form", nullptr));
        label->setText(QApplication::translate("MRMessageBox", "TextLabel", nullptr));
        MRMBClose->setText(QString());
        MRMBIcon->setText(QApplication::translate("MRMessageBox", "TextLabel", nullptr));
        MRMBText->setText(QApplication::translate("MRMessageBox", "TextLabel", nullptr));
        MRMBDetail->setText(QApplication::translate("MRMessageBox", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MRMessageBox: public Ui_MRMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRMESSAGEBOX_H
