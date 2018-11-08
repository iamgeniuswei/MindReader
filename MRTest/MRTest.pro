QT += testlib
QT += gui widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app
CONFIG(debug, debug|release):DESTDIR = ../
else:DESTDIR = ../release
SOURCES +=  tst_testmradc.cpp


LIBS += "C:/Program Files (x86)/Windows Kits/10/Lib/10.0.10150.0/ucrt/x86/ucrtd.lib"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../UIControl/release/ -lUIControl
else:win32:CONFIG(debug, debug|release): LIBS += -L../ -lUIControl
else:unix: LIBS += -L$$OUT_PWD/../UIControl/ -lUIControl

INCLUDEPATH += $$PWD/../UIControl
DEPENDPATH += $$PWD/../UIControl


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


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Window/release/ -lWindow
else:win32:CONFIG(debug, debug|release): LIBS += -L../ -lWindow
else:unix: LIBS += -L$$OUT_PWD/../Window/ -lWindow

INCLUDEPATH += $$PWD/../Window
DEPENDPATH += $$PWD/../Window

INCLUDEPATH += D:\lib\tesseract\include
LIBS += D:\lib\tesseract\lib\tesseract40d.lib
LIBS += D:\lib\tesseract\lib\pvt.cppan.demo.danbloomberg.leptonica-1.76.0.lib
