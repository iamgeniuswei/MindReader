/********************************************************************************
** Form generated from reading UI file 'articledisplayercontroller.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARTICLEDISPLAYERCONTROLLER_H
#define UI_ARTICLEDISPLAYERCONTROLLER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArticleDisplayerController
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *firstPageBtn;
    QPushButton *prevPageBtn;
    QComboBox *ADCIndex;
    QPushButton *nextPageBtn;
    QPushButton *lastPageBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *page;
    QPushButton *pageBreak;
    QComboBox *comboBox;
    QPushButton *zoomInBtn;
    QSlider *horizontalSlider;
    QPushButton *zoomOutBtn;
    QButtonGroup *ADCPageFormat;

    void setupUi(QWidget *ArticleDisplayerController)
    {
        if (ArticleDisplayerController->objectName().isEmpty())
            ArticleDisplayerController->setObjectName(QString::fromUtf8("ArticleDisplayerController"));
        ArticleDisplayerController->resize(700, 50);
        horizontalLayout = new QHBoxLayout(ArticleDisplayerController);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        firstPageBtn = new QPushButton(ArticleDisplayerController);
        firstPageBtn->setObjectName(QString::fromUtf8("firstPageBtn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/first"), QSize(), QIcon::Normal, QIcon::Off);
        firstPageBtn->setIcon(icon);
        firstPageBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(firstPageBtn);

        prevPageBtn = new QPushButton(ArticleDisplayerController);
        prevPageBtn->setObjectName(QString::fromUtf8("prevPageBtn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/backward"), QSize(), QIcon::Normal, QIcon::Off);
        prevPageBtn->setIcon(icon1);
        prevPageBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(prevPageBtn);

        ADCIndex = new QComboBox(ArticleDisplayerController);
        ADCIndex->setObjectName(QString::fromUtf8("ADCIndex"));

        horizontalLayout->addWidget(ADCIndex);

        nextPageBtn = new QPushButton(ArticleDisplayerController);
        nextPageBtn->setObjectName(QString::fromUtf8("nextPageBtn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/forward"), QSize(), QIcon::Normal, QIcon::Off);
        nextPageBtn->setIcon(icon2);
        nextPageBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(nextPageBtn);

        lastPageBtn = new QPushButton(ArticleDisplayerController);
        lastPageBtn->setObjectName(QString::fromUtf8("lastPageBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/last"), QSize(), QIcon::Normal, QIcon::Off);
        lastPageBtn->setIcon(icon3);
        lastPageBtn->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(lastPageBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        page = new QPushButton(ArticleDisplayerController);
        ADCPageFormat = new QButtonGroup(ArticleDisplayerController);
        ADCPageFormat->setObjectName(QString::fromUtf8("ADCPageFormat"));
        ADCPageFormat->addButton(page);
        page->setObjectName(QString::fromUtf8("page"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/page"), QSize(), QIcon::Normal, QIcon::Off);
        page->setIcon(icon4);
        page->setIconSize(QSize(20, 20));
        page->setCheckable(true);

        horizontalLayout->addWidget(page);

        pageBreak = new QPushButton(ArticleDisplayerController);
        ADCPageFormat->addButton(pageBreak);
        pageBreak->setObjectName(QString::fromUtf8("pageBreak"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/page-break"), QSize(), QIcon::Normal, QIcon::Off);
        pageBreak->setIcon(icon5);
        pageBreak->setIconSize(QSize(20, 20));
        pageBreak->setCheckable(true);

        horizontalLayout->addWidget(pageBreak);

        comboBox = new QComboBox(ArticleDisplayerController);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        zoomInBtn = new QPushButton(ArticleDisplayerController);
        zoomInBtn->setObjectName(QString::fromUtf8("zoomInBtn"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/zoomIn"), QSize(), QIcon::Normal, QIcon::Off);
        zoomInBtn->setIcon(icon6);
        zoomInBtn->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(zoomInBtn);

        horizontalSlider = new QSlider(ArticleDisplayerController);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(100, 16777215));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        zoomOutBtn = new QPushButton(ArticleDisplayerController);
        zoomOutBtn->setObjectName(QString::fromUtf8("zoomOutBtn"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/zoomOut"), QSize(), QIcon::Normal, QIcon::Off);
        zoomOutBtn->setIcon(icon7);
        zoomOutBtn->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(zoomOutBtn);


        retranslateUi(ArticleDisplayerController);

        QMetaObject::connectSlotsByName(ArticleDisplayerController);
    } // setupUi

    void retranslateUi(QWidget *ArticleDisplayerController)
    {
        ArticleDisplayerController->setWindowTitle(QApplication::translate("ArticleDisplayerController", "Form", nullptr));
        firstPageBtn->setText(QString());
        prevPageBtn->setText(QString());
        nextPageBtn->setText(QString());
        lastPageBtn->setText(QString());
        page->setText(QString());
        pageBreak->setText(QString());
        comboBox->setItemText(0, QApplication::translate("ArticleDisplayerController", "50%", nullptr));
        comboBox->setItemText(1, QApplication::translate("ArticleDisplayerController", "100%", nullptr));
        comboBox->setItemText(2, QApplication::translate("ArticleDisplayerController", "150%", nullptr));
        comboBox->setItemText(3, QApplication::translate("ArticleDisplayerController", "200%", nullptr));

        zoomInBtn->setText(QString());
        zoomOutBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ArticleDisplayerController: public Ui_ArticleDisplayerController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARTICLEDISPLAYERCONTROLLER_H