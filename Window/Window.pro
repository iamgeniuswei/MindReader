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
    articleitem.cpp \
    articlepagerender.cpp \
    articledisplayercontroller.cpp \
    notecard.cpp \
    notedisplayer.cpp \
    widgetinterface.cpp \
    readerwithnote.cpp \
    mrworkdirsettingwindow.cpp \
    mrmainwindow.cpp \
    mrlibrarytoolbar.cpp \
    mrlibrary.cpp \
    mrreadertoolbar.cpp \
    mrlibrarytree.cpp \
    mrarticlescanner.cpp \
    mrmessagebox.cpp \
    mrarticleitem.cpp \
    mrwindowutility.cpp \
    mrarticleshelf.cpp \
    mrarticlepagedisplayer.cpp \
    mrarticlereader.cpp \
    mrcursor.cpp \
    mrarticlepagepainter.cpp \
    mrocrrecognizer.cpp \
    mrarticledisplayer.cpp \
    mrarticleloader.cpp \
    mrsinglepagedisplayer.cpp \
    mrseriespagedisplayer.cpp \
    mrpageannotationhelper.cpp

HEADERS += \
        window.h \
        window_global.h \ 
    articleitem.h \
    articlepagerender.h \
    articledisplayercontroller.h \
    notecard.h \
    notedisplayer.h \
    widgetinterface.h \
    readerwithnote.h \
    mrworkdirsettingwindow.h \
    mrmainwindow.h \
    mrlibrarytoolbar.h \
    mrlibrary.h \
    mrreadertoolbar.h \
    mrwindowutility.h \
    mrlibrarytree.h \
    mrarticlescanner.h \
    mrmessagebox.h \
    mrarticleitem.h \
    mrarticleshelf.h \
    mrarticlepagedisplayer.h \
    mrarticlereader.h \
    private/mrarticlepagedisplayer_p.h \
    mrcursor.h \
    mrarticlepagepainter.h \
    mrocrrecognizer.h \
    mrarticledisplayer.h \
    mrarticleloader.h \
    mrsinglepagedisplayer.h \
    mrseriespagedisplayer.h \
    mrpageannotationhelper.h

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
    articledisplayercontroller.ui \
    notecard.ui \
    mrworkdirsettingwindow.ui \
    mrmainwindow.ui \
    mrlibrarytoolbar.ui \
    mrreadertoolbar.ui \
    mrlibrarytree.ui \
    mrmessagebox.ui \
    mrarticleitem.ui



INCLUDEPATH += D:\Project\mupdf\include

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Utility/release/ -lUtility
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Utility/debug/ -lUtility
else:unix: LIBS += -L$$OUT_PWD/../Utility/ -lUtility

INCLUDEPATH += $$PWD/../Utility
DEPENDPATH += $$PWD/../Utility

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MRData/release/ -lMRData
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MRData/debug/ -lMRData
else:unix: LIBS += -L$$OUT_PWD/../MRData/ -lMRData

INCLUDEPATH += $$PWD/../MRData
DEPENDPATH += $$PWD/../MRData

#INCLUDEPATH += D:\Project\MindReader\UIControls
#LIBS += D:\lib\uilabelplugin.lib

INCLUDEPATH += D:\lib\odb\include
LIBS += D:\lib\odb\lib\odb-d.lib
LIBS += D:\lib\odb\lib\odb-sqlite-d.lib
INCLUDEPATH += D:\Project\mupdf\include
LIBS += D:\Project\mupdf\lib\libmupdf.lib
LIBS += D:\Project\mupdf\lib\libthirdparty.lib
LIBS += D:\Project\mupdf\lib\libresources.lib

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MREngine/release/ -lMREngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MREngine/debug/ -lMREngine
else:unix: LIBS += -L$$OUT_PWD/../MREngine/ -lMREngine

INCLUDEPATH += $$PWD/../MREngine
DEPENDPATH += $$PWD/../MREngine


INCLUDEPATH += D:\lib\tesseract\include
LIBS += D:\lib\tesseract\lib\tesseract40d.lib
LIBS += D:\lib\tesseract\lib\pvt.cppan.demo.danbloomberg.leptonica-1.76.0.lib
