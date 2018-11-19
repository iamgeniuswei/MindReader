/********************************************************************************
** Form generated from reading UI file 'mrlibrarytoolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRLIBRARYTOOLBAR_H
#define UI_MRLIBRARYTOOLBAR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MRLibraryToolBar
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *line;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *MRLibraryToolBar)
    {
        if (MRLibraryToolBar->objectName().isEmpty())
            MRLibraryToolBar->setObjectName(QString::fromUtf8("MRLibraryToolBar"));
        MRLibraryToolBar->resize(400, 48);
        horizontalLayout = new QHBoxLayout(MRLibraryToolBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        pushButton = new QPushButton(MRLibraryToolBar);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/grid"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(MRLibraryToolBar);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/list"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(pushButton_2);

        line = new QFrame(MRLibraryToolBar);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        lineEdit = new QLineEdit(MRLibraryToolBar);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(115, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(MRLibraryToolBar);

        QMetaObject::connectSlotsByName(MRLibraryToolBar);
    } // setupUi

    void retranslateUi(QWidget *MRLibraryToolBar)
    {
        MRLibraryToolBar->setWindowTitle(QApplication::translate("MRLibraryToolBar", "Form", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MRLibraryToolBar: public Ui_MRLibraryToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRLIBRARYTOOLBAR_H
