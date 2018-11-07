QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase



TEMPLATE = app

CONFIG(debug, debug|release):DESTDIR = ../
else:DESTDIR = ../release

SOURCES +=  tst_pdfpagetest.cpp
#INCLUDEPATH += "C:/Program Files (x86)/Windows Kits/10/Include/10.0.10150.0/ucrt"
LIBS += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10150.0/ucrt/x86/ucrtd.lib"




INCLUDEPATH += D:\Project\mupdf\include
LIBS += D:\Project\mupdf\lib\libmupdf.lib
LIBS += D:\Project\mupdf\lib\libthirdparty.lib
LIBS += D:\Project\mupdf\lib\libresources.lib


LIBS += D:\Project\MindReader\debug\MREngine.lib

INCLUDEPATH += $$PWD/../MREngine
DEPENDPATH += $$PWD/../MREngine
