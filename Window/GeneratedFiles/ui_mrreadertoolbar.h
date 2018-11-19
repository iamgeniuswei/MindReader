/********************************************************************************
** Form generated from reading UI file 'mrreadertoolbar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MRREADERTOOLBAR_H
#define UI_MRREADERTOOLBAR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MRReaderToolBar
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *library;
    QFrame *sep_1;
    QPushButton *save;
    QFrame *line_2;
    QPushButton *hand;
    QPushButton *select;
    QPushButton *screenshot;
    QPushButton *line;
    QPushButton *rectangle;
    QPushButton *text;
    QPushButton *color;
    QSpacerItem *horizontalSpacer;
    QPushButton *note;
    QPushButton *exportNote;

    void setupUi(QWidget *MRReaderToolBar)
    {
        if (MRReaderToolBar->objectName().isEmpty())
            MRReaderToolBar->setObjectName(QString::fromUtf8("MRReaderToolBar"));
        MRReaderToolBar->resize(648, 40);
        MRReaderToolBar->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(MRReaderToolBar);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        library = new QPushButton(MRReaderToolBar);
        library->setObjectName(QString::fromUtf8("library"));
        library->setMinimumSize(QSize(0, 36));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/library"), QSize(), QIcon::Normal, QIcon::Off);
        library->setIcon(icon);
        library->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(library);

        sep_1 = new QFrame(MRReaderToolBar);
        sep_1->setObjectName(QString::fromUtf8("sep_1"));
        sep_1->setFrameShape(QFrame::VLine);
        sep_1->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(sep_1);

        save = new QPushButton(MRReaderToolBar);
        save->setObjectName(QString::fromUtf8("save"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/save"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon1);
        save->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(save);

        line_2 = new QFrame(MRReaderToolBar);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        hand = new QPushButton(MRReaderToolBar);
        hand->setObjectName(QString::fromUtf8("hand"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/hand"), QSize(), QIcon::Normal, QIcon::Off);
        hand->setIcon(icon2);
        hand->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(hand);

        select = new QPushButton(MRReaderToolBar);
        select->setObjectName(QString::fromUtf8("select"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/select"), QSize(), QIcon::Normal, QIcon::Off);
        select->setIcon(icon3);
        select->setIconSize(QSize(20, 20));
        select->setCheckable(true);
        select->setChecked(false);

        horizontalLayout->addWidget(select);

        screenshot = new QPushButton(MRReaderToolBar);
        screenshot->setObjectName(QString::fromUtf8("screenshot"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/screenshot"), QSize(), QIcon::Normal, QIcon::Off);
        screenshot->setIcon(icon4);
        screenshot->setIconSize(QSize(20, 20));
        screenshot->setCheckable(true);

        horizontalLayout->addWidget(screenshot);

        line = new QPushButton(MRReaderToolBar);
        line->setObjectName(QString::fromUtf8("line"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/line"), QSize(), QIcon::Normal, QIcon::Off);
        line->setIcon(icon5);
        line->setIconSize(QSize(20, 20));
        line->setCheckable(true);
        line->setChecked(false);

        horizontalLayout->addWidget(line);

        rectangle = new QPushButton(MRReaderToolBar);
        rectangle->setObjectName(QString::fromUtf8("rectangle"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/rectangle"), QSize(), QIcon::Normal, QIcon::Off);
        rectangle->setIcon(icon6);
        rectangle->setIconSize(QSize(20, 20));
        rectangle->setCheckable(true);
        rectangle->setChecked(false);

        horizontalLayout->addWidget(rectangle);

        text = new QPushButton(MRReaderToolBar);
        text->setObjectName(QString::fromUtf8("text"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/text"), QSize(), QIcon::Normal, QIcon::Off);
        text->setIcon(icon7);
        text->setIconSize(QSize(20, 20));
        text->setCheckable(true);

        horizontalLayout->addWidget(text);

        color = new QPushButton(MRReaderToolBar);
        color->setObjectName(QString::fromUtf8("color"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/color"), QSize(), QIcon::Normal, QIcon::Off);
        color->setIcon(icon8);
        color->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(color);

        horizontalSpacer = new QSpacerItem(173, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        note = new QPushButton(MRReaderToolBar);
        note->setObjectName(QString::fromUtf8("note"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/notes"), QSize(), QIcon::Normal, QIcon::Off);
        note->setIcon(icon9);
        note->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(note);

        exportNote = new QPushButton(MRReaderToolBar);
        exportNote->setObjectName(QString::fromUtf8("exportNote"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/export"), QSize(), QIcon::Normal, QIcon::Off);
        exportNote->setIcon(icon10);
        exportNote->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(exportNote);


        retranslateUi(MRReaderToolBar);

        QMetaObject::connectSlotsByName(MRReaderToolBar);
    } // setupUi

    void retranslateUi(QWidget *MRReaderToolBar)
    {
        MRReaderToolBar->setWindowTitle(QApplication::translate("MRReaderToolBar", "Form", nullptr));
        library->setText(QApplication::translate("MRReaderToolBar", "\345\233\276\344\271\246\351\246\206", nullptr));
        save->setText(QString());
        hand->setText(QString());
#ifndef QT_NO_TOOLTIP
        select->setToolTip(QApplication::translate("MRReaderToolBar", "<html><head/><body><p>\345\214\272\345\237\237\351\200\211\346\213\251\345\267\245\345\205\267\357\274\214\351\200\211\346\213\251\345\214\272\345\237\237\346\226\207\346\234\254\357\274\214\351\253\230\344\272\256\345\271\266\350\207\252\345\212\250\345\210\233\345\273\272\351\230\205\350\257\273\346\221\230\350\246\201</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        select->setText(QString());
#ifndef QT_NO_TOOLTIP
        screenshot->setToolTip(QApplication::translate("MRReaderToolBar", "<html><head/><body><p>\345\233\276\345\203\217\345\267\245\345\205\267</p><p>\346\210\252\345\217\226\345\233\276\345\203\217</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        screenshot->setText(QString());
#ifndef QT_NO_TOOLTIP
        line->setToolTip(QApplication::translate("MRReaderToolBar", "<html><head/><body><p>\347\272\277\346\235\241\345\267\245\345\205\267</p><p><br/></p><p>\347\273\230\345\210\266\347\233\264\347\272\277\357\274\214\346\214\211\344\275\217shift\357\274\214\347\273\230\345\210\266\346\260\264\345\271\263\347\233\264\347\272\277</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        line->setText(QString());
#ifndef QT_NO_TOOLTIP
        rectangle->setToolTip(QApplication::translate("MRReaderToolBar", "<html><head/><body><p>\347\237\251\345\275\242\345\267\245\345\205\267</p><p><br/></p><p>\347\273\230\345\210\266\347\237\251\345\275\242\357\274\214\346\214\211\344\275\217shift\347\273\230\345\210\266\346\255\243\346\226\271\345\275\242</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        rectangle->setText(QString());
#ifndef QT_NO_TOOLTIP
        text->setToolTip(QApplication::translate("MRReaderToolBar", "<html><head/><body><p>\346\226\207\346\234\254\345\267\245\345\205\267</p><p><br/></p><p>\345\234\250\351\241\265\351\235\242\344\270\212\345\242\236\345\212\240\346\226\207\346\234\254</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        text->setText(QString());
        color->setText(QString());
        note->setText(QApplication::translate("MRReaderToolBar", "\351\232\220\350\227\217\347\254\224\350\256\260\346\234\254", nullptr));
        exportNote->setText(QApplication::translate("MRReaderToolBar", "\345\257\274\345\207\272\346\200\235\347\273\264\345\257\274\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MRReaderToolBar: public Ui_MRReaderToolBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MRREADERTOOLBAR_H
