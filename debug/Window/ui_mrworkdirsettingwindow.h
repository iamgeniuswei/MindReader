/********************************************************************************
** Form generated from reading UI file 'mrworkdirsettingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRWORKDIRSETTINGWINDOW_H
#define UI_MRWORKDIRSETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MRWorkDirSettingWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *close;
    QLabel *label_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *browserBtn;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirm;
    QPushButton *ignore;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *MRWorkDirSettingWindow)
    {
        if (MRWorkDirSettingWindow->objectName().isEmpty())
            MRWorkDirSettingWindow->setObjectName(QString::fromUtf8("MRWorkDirSettingWindow"));
        MRWorkDirSettingWindow->resize(458, 319);
        MRWorkDirSettingWindow->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(MRWorkDirSettingWindow);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MRWorkDirSettingWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("border-image: url(:/img/background);"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        close = new QPushButton(widget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setStyleSheet(QString::fromUtf8("border-image:none;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/close"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon);
        close->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(close);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 80));
        label_2->setStyleSheet(QString::fromUtf8("border-image:none;background:transparent;"));
        label_2->setScaledContents(true);

        verticalLayout_2->addWidget(label_2);


        verticalLayout_3->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, -1, 9, -1);
        label = new QLabel(MRWorkDirSettingWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setScaledContents(true);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        lineEdit = new QLineEdit(MRWorkDirSettingWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 36));
        lineEdit->setFont(font);
        lineEdit->setStyleSheet(QString::fromUtf8("border-image:none;"));

        horizontalLayout->addWidget(lineEdit);

        browserBtn = new QPushButton(MRWorkDirSettingWindow);
        browserBtn->setObjectName(QString::fromUtf8("browserBtn"));
        browserBtn->setStyleSheet(QString::fromUtf8("border-image:none;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/browser"), QSize(), QIcon::Normal, QIcon::Off);
        browserBtn->setIcon(icon1);
        browserBtn->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(browserBtn);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 32, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        confirm = new QPushButton(MRWorkDirSettingWindow);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(confirm->sizePolicy().hasHeightForWidth());
        confirm->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        confirm->setFont(font1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/ok"), QSize(), QIcon::Normal, QIcon::Off);
        confirm->setIcon(icon2);
        confirm->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(confirm);

        ignore = new QPushButton(MRWorkDirSettingWindow);
        ignore->setObjectName(QString::fromUtf8("ignore"));
        ignore->setFont(font1);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/later"), QSize(), QIcon::Normal, QIcon::Off);
        ignore->setIcon(icon3);
        ignore->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(ignore);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 32, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        retranslateUi(MRWorkDirSettingWindow);

        QMetaObject::connectSlotsByName(MRWorkDirSettingWindow);
    } // setupUi

    void retranslateUi(QWidget *MRWorkDirSettingWindow)
    {
        MRWorkDirSettingWindow->setWindowTitle(QApplication::translate("MRWorkDirSettingWindow", "Form", nullptr));
        close->setText(QString());
        label_2->setText(QApplication::translate("MRWorkDirSettingWindow", "TextLabel", nullptr));
        label->setText(QApplication::translate("MRWorkDirSettingWindow", "\350\256\276\347\275\256\345\267\245\344\275\234\347\233\256\345\275\225\357\274\232", nullptr));
        browserBtn->setText(QString());
        confirm->setText(QApplication::translate("MRWorkDirSettingWindow", "\347\241\256\345\256\232", nullptr));
        ignore->setText(QApplication::translate("MRWorkDirSettingWindow", "\347\250\215\345\220\216\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MRWorkDirSettingWindow: public Ui_MRWorkDirSettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRWORKDIRSETTINGWINDOW_H
