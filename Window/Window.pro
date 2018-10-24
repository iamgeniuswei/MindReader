#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T16:30:54
#
#-------------------------------------------------

QT       += widgets

TARGET = Window
TEMPLATE = lib

CONFIG(debug, debug|release):DESTDIR = ../
else:DESTDIR = ../release



DEFINES += WINDOW_LIBRARY

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
        window.cpp \
    articleshelf.cpp \
    articleitem.cpp \
    articlescanner.cpp \
    mainwindow.cpp \
    articlereader.cpp \
    ArticleDisplayer.cpp \
    ArticlePage.cpp \
    articlepagerender.cpp \
    articledisplayercontroller.cpp \
    notecard.cpp \
    notedisplayer.cpp \
    widgetinterface.cpp \
    readerwithnote.cpp

HEADERS += \
        window.h \
        window_global.h \ 
    articleshelf.h \
    articleitem.h \
    articlescanner.h \
    mainwindow.h \
    articlereader.h \
    ArticleDisplayer.h \
    ArticlePage.h \
    articlepagerender.h \
    articledisplayercontroller.h \
    notecard.h \
    notedisplayer.h \
    widgetinterface.h \
    readerwithnote.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10150.0/ucrt"
LIBS += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10150.0/ucrt/x86/ucrtd.lib"



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UIControl/release/ -lUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L../ -lUIControl
else:unix: LIBS += -L$$OUT_PWD/../UIControl/ -lUIControl

INCLUDEPATH += $$PWD/../UIControl
DEPENDPATH += $$PWD/../UIControl

FORMS += \
    mainwindow.ui \
    articledisplayercontroller.ui \
    notecard.ui

win32:CONFIG(release, debug|release): LIBS += -L../ -lPDFCore
else:win32:CONFIG(debug, debug|release): LIBS += -L../ -lPDFCore
else:unix: LIBS += -L../ -lPDFCore

INCLUDEPATH += $$PWD/../PDFCore
DEPENDPATH += $$PWD/../PDFCore
INCLUDEPATH += D:\Project\mupdf\include
