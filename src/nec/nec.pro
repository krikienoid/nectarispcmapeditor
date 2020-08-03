include(../../defaults.pri)

CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = lib

TARGET = neclib

SOURCES += \
    biginfo.cpp \
    bigmap.cpp \
    bigunit.cpp \
    datamanager.cpp \
    coordinates.cpp \
    mapinfo.cpp \
    mapmap.cpp \
    mapname.cpp \
    playerrole.cpp \
    playerstance.cpp \
    ter.cpp \
    tertype.cpp \
    mapunit.cpp

HEADERS += \
    biginfo.h \
    bigmap.h \
    bigunit.h \
    datamanager.h \
    coordinates.h \
    mapinfo.h \
    mapmap.h \
    mapname.h \
    playerrole.h \
    playerstance.h \
    ter.h \
    tertype.h \
    mapunit.h

# Byte Lib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../raw/release/ -lblib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../raw/debug/ -lblib
else:unix: LIBS += -L$$OUT_PWD/../raw/ -lblib
INCLUDEPATH += $$PWD/../raw
DEPENDPATH += $$PWD/../raw
