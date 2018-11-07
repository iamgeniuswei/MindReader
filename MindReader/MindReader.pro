#-------------------------------------------------
#
# Project created by QtCreator 2018-10-17T16:05:55
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = MindReader
TEMPLATE = app
CONFIG(debug, debug|release):DESTDIR = ../
else:DESTDIR = ../release
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp

HEADERS +=

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10150.0/ucrt"
LIBS += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10150.0/ucrt/x86/ucrtd.lib"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UIControl/release/ -lUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L../ -lUIControl
else:unix: LIBS += -L$$OUT_PWD/../UIControl/ -lUIControl

INCLUDEPATH += $$PWD/../UIControl
DEPENDPATH += $$PWD/../UIControl

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Window/release/ -lWindow
else:win32:CONFIG(debug, debug|release): LIBS += -L../ -lWindow
else:unix: LIBS += -L$$OUT_PWD/../Window/ -lWindow

INCLUDEPATH += $$PWD/../Window
DEPENDPATH += $$PWD/../Window

RESOURCES += \
    res/resource.qrc
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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MREngine/release/ -lMREngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MREngine/debug/ -lMREngine
else:unix: LIBS += -L$$OUT_PWD/../MREngine/ -lMREngine

INCLUDEPATH += $$PWD/../MREngine
DEPENDPATH += $$PWD/../MREngine
