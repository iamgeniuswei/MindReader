CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(uilabelplugin)
TEMPLATE    = lib

HEADERS     = uilabelplugin.h
SOURCES     = uilabelplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 
CONFIG(debug, debug|release):DESTDIR = ../
else:DESTDIR = ../release
greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(uilabel.pri)
INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10150.0/ucrt"
LIBS += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10150.0/ucrt/x86/ucrtd.lib"
LIBS += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10150.0/ucrt/x86/ucrt.lib"
