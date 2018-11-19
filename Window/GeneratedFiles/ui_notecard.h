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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <uitextedit.h>
#include "uilabel.h"

QT_BEGIN_NAMESPACE

class Ui_NoteCard
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *title;
    QSpacerItem *horizontalSpacer;
    UILabel *index;
    QPushButton *trash;
    QLabel *content;
    QFrame *line;
    UITextEdit *note;

    void setupUi(QWidget *NoteCard)
    {
        if (NoteCard->objectName().isEmpty())
            NoteCard->setObjectName(QString::fromUtf8("NoteCard"));
        NoteCard->resize(320, 103);
        NoteCard->setMinimumSize(QSize(320, 0));
        NoteCard->setMaximumSize(QSize(418, 16777215));
        NoteCard->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 0, 0);"));
        verticalLayout = new QVBoxLayout(NoteCard);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        title = new QLineEdit(NoteCard);
        title->setObjectName(QString::fromUtf8("title"));
        title->setClearButtonEnabled(false);

        horizontalLayout->addWidget(title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        index = new UILabel(NoteCard);
        index->setObjectName(QString::fromUtf8("index"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(index->sizePolicy().hasHeightForWidth());
        index->setSizePolicy(sizePolicy);
        index->setMinimumSize(QSize(28, 28));
        index->setMaximumSize(QSize(28, 27));
        index->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(index);

        trash = new QPushButton(NoteCard);
        trash->setObjectName(QString::fromUtf8("trash"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/delete"), QSize(), QIcon::Normal, QIcon::Off);
        trash->setIcon(icon);
        trash->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(trash);


        verticalLayout->addLayout(horizontalLayout);

        content = new QLabel(NoteCard);
        content->setObjectName(QString::fromUtf8("content"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(content->sizePolicy().hasHeightForWidth());
        content->setSizePolicy(sizePolicy1);
        content->setMinimumSize(QSize(0, 0));
        content->setTextFormat(Qt::RichText);
        content->setScaledContents(true);
        content->setWordWrap(true);

        verticalLayout->addWidget(content);

        line = new QFrame(NoteCard);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        note = new UITextEdit(NoteCard);
        note->setObjectName(QString::fromUtf8("note"));
        sizePolicy1.setHeightForWidth(note->sizePolicy().hasHeightForWidth());
        note->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(note);

        verticalLayout->setStretch(1, 1);

        retranslateUi(NoteCard);

        QMetaObject::connectSlotsByName(NoteCard);
    } // setupUi

    void retranslateUi(QWidget *NoteCard)
    {
        NoteCard->setWindowTitle(QApplication::translate("NoteCard", "Form", nullptr));
        title->setPlaceholderText(QApplication::translate("NoteCard", "\346\234\252\345\221\275\345\220\215\347\254\224\350\256\260", nullptr));
#ifndef QT_NO_TOOLTIP
        index->setToolTip(QApplication::translate("NoteCard", "\350\267\263\350\275\254\345\210\260\351\241\265\351\235\242", nullptr));
#endif // QT_NO_TOOLTIP
        index->setText(QApplication::translate("NoteCard", "0", nullptr));
#ifndef QT_NO_TOOLTIP
        trash->setToolTip(QApplication::translate("NoteCard", "\345\210\240\351\231\244\347\254\224\350\256\260", nullptr));
#endif // QT_NO_TOOLTIP
        trash->setText(QString());
        content->setText(QString());
        note->setPlaceholderText(QApplication::translate("NoteCard", "\346\267\273\345\212\240\347\254\224\350\256\260...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NoteCard: public Ui_NoteCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTECARD_H
