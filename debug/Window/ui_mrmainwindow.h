/********************************************************************************
** Form generated from reading UI file 'mrmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRMAINWINDOW_H
#define UI_MRMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MRMainWindow
{
public:
    QAction *actionOpen_Ariticle;
    QAction *actionClose_Article;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MRMainWindow)
    {
        if (MRMainWindow->objectName().isEmpty())
            MRMainWindow->setObjectName(QString::fromUtf8("MRMainWindow"));
        MRMainWindow->resize(800, 600);
        actionOpen_Ariticle = new QAction(MRMainWindow);
        actionOpen_Ariticle->setObjectName(QString::fromUtf8("actionOpen_Ariticle"));
        actionClose_Article = new QAction(MRMainWindow);
        actionClose_Article->setObjectName(QString::fromUtf8("actionClose_Article"));
        centralwidget = new QWidget(MRMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MRMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MRMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MRMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MRMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MRMainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionOpen_Ariticle);
        menu->addAction(actionClose_Article);

        retranslateUi(MRMainWindow);

        QMetaObject::connectSlotsByName(MRMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MRMainWindow)
    {
        MRMainWindow->setWindowTitle(QApplication::translate("MRMainWindow", "MainWindow", nullptr));
        actionOpen_Ariticle->setText(QApplication::translate("MRMainWindow", "Open Ariticle", nullptr));
        actionClose_Article->setText(QApplication::translate("MRMainWindow", "Close Article", nullptr));
        menu->setTitle(QApplication::translate("MRMainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MRMainWindow: public Ui_MRMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRMAINWINDOW_H
