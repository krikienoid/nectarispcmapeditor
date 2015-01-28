include(../../defaults.pri)

CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = lib

TARGET = neclib

SOURCES += \
    necbiginfo.cpp \
    necbigmap.cpp \
    necbigunit.cpp \
    necdatamanager.cpp \
    neccoordinates.cpp \
    necmapinfo.cpp \
    necmapmap.cpp \
    necmapname.cpp \
    necplayerrole.cpp \
    necplayerstance.cpp \
    necter.cpp \
    nectertype.cpp \
    necmapunit.cpp

HEADERS += \
    necbiginfo.h \
    necbigmap.h \
    necbigunit.h \
    necdatamanager.h \
    neccoordinates.h \
    necmapinfo.h \
    necmapmap.h \
    necmapname.h \
    necplayerrole.h \
    necplayerstance.h \
    necter.h \
    nectertype.h \
    necmapunit.h

# Byte Lib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../bytes/release/ -lblib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../bytes/debug/ -lblib
else:unix: LIBS += -L$$OUT_PWD/../bytes/ -lblib
INCLUDEPATH += $$PWD/../bytes
DEPENDPATH += $$PWD/../bytes
