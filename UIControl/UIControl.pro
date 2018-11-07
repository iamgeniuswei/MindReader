#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T16:24:51
#
#-------------------------------------------------

QT       += widgets

TARGET = UIControl
TEMPLATE = lib
CONFIG(debug, debug|release):DESTDIR = ../
else:DESTDIR = ../release
DEFINES += UICONTROL_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        uicontrol.cpp \
    QIconButton.cpp \
    QImageTextItem.cpp \
    qimagetextwidget.cpp \
    uiwidget.cpp \
    uilabel.cpp \
    uidialog.cpp \
    uiflowlayout.cpp

HEADERS += \
        uicontrol.h \
        uicontrol_global.h \ 
    QIconButton.h \
    QImageTextItem.h \
    private/QIconButton_p.h \
    qimagetextwidget.h \
    uiwidget.h \
    uilabel.h \
    uidialog.h \
    uiflowlayout.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10150.0/ucrt"
LIBS += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10150.0/ucrt/x86/ucrtd.lib"

FORMS += \
    qimagetextwidget.ui
