/********************************************************************************
** Form generated from reading UI file 'notecard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTECARD_H
#define UI_NOTECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NoteCard
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QToolButton *toolButton;
    QTextBrowser *textBrowser;
    QFrame *line;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *NoteCard)
    {
        if (NoteCard->objectName().isEmpty())
            NoteCard->setObjectName(QString::fromUtf8("NoteCard"));
        NoteCard->resize(400, 300);
        verticalLayout = new QVBoxLayout(NoteCard);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(NoteCard);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(NoteCard);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        toolButton = new QToolButton(NoteCard);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(NoteCard);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        line = new QFrame(NoteCard);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        plainTextEdit = new QPlainTextEdit(NoteCard);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        verticalLayout->addWidget(plainTextEdit);


        retranslateUi(NoteCard);

        QMetaObject::connectSlotsByName(NoteCard);
    } // setupUi

    void retranslateUi(QWidget *NoteCard)
    {
        NoteCard->setWindowTitle(QApplication::translate("NoteCard", "Form", nullptr));
        label->setText(QApplication::translate("NoteCard", "TextLabel", nullptr));
        toolButton->setText(QApplication::translate("NoteCard", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteCard: public Ui_NoteCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTECARD_H
