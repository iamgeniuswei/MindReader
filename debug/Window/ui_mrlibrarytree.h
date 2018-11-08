/********************************************************************************
** Form generated from reading UI file 'mrlibrarytree.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRLIBRARYTREE_H
#define UI_MRLIBRARYTREE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MRLibraryTree
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *MRLTIcon;
    QLabel *MRLTTitle;
    QSpacerItem *horizontalSpacer;
    QPushButton *MRLTRefresh;
    QTreeView *articleTree;

    void setupUi(QWidget *MRLibraryTree)
    {
        if (MRLibraryTree->objectName().isEmpty())
            MRLibraryTree->setObjectName(QString::fromUtf8("MRLibraryTree"));
        MRLibraryTree->resize(292, 524);
        verticalLayout = new QVBoxLayout(MRLibraryTree);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MRLTIcon = new QLabel(MRLibraryTree);
        MRLTIcon->setObjectName(QString::fromUtf8("MRLTIcon"));
        MRLTIcon->setPixmap(QPixmap(QString::fromUtf8(":/img/library")));
        MRLTIcon->setScaledContents(true);

        horizontalLayout->addWidget(MRLTIcon);

        MRLTTitle = new QLabel(MRLibraryTree);
        MRLTTitle->setObjectName(QString::fromUtf8("MRLTTitle"));

        horizontalLayout->addWidget(MRLTTitle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        MRLTRefresh = new QPushButton(MRLibraryTree);
        MRLTRefresh->setObjectName(QString::fromUtf8("MRLTRefresh"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/refresh"), QSize(), QIcon::Normal, QIcon::Off);
        MRLTRefresh->setIcon(icon);
        MRLTRefresh->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(MRLTRefresh);


        verticalLayout->addLayout(horizontalLayout);

        articleTree = new QTreeView(MRLibraryTree);
        articleTree->setObjectName(QString::fromUtf8("articleTree"));
        articleTree->setIndentation(20);
        articleTree->header()->setVisible(false);

        verticalLayout->addWidget(articleTree);


        retranslateUi(MRLibraryTree);

        QMetaObject::connectSlotsByName(MRLibraryTree);
    } // setupUi

    void retranslateUi(QWidget *MRLibraryTree)
    {
        MRLibraryTree->setWindowTitle(QApplication::translate("MRLibraryTree", "Form", nullptr));
        MRLTIcon->setText(QString());
        MRLTTitle->setText(QApplication::translate("MRLibraryTree", "\346\226\207\346\241\243\345\272\223", nullptr));
        MRLTRefresh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MRLibraryTree: public Ui_MRLibraryTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRLIBRARYTREE_H
