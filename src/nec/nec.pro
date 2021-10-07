include(../../defaults.pri)

CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = lib

TARGET = neclib

SOURCES += \
    biginfo.cpp \
    bigmap.cpp \
    bigunit.cpp \
    filedata.cpp \
    levelinfo.cpp \
    levelmap.cpp \
    levelname.cpp \
    levelunit.cpp \
    mapposition.cpp \
    playerattitude.cpp \
    playerrole.cpp \
    ter.cpp \
    tertype.cpp

HEADERS += \
    biginfo.h \
    bigmap.h \
    bigunit.h \
    filedata.h \
    levelinfo.h \
    levelmap.h \
    levelname.h \
    levelunit.h \
    mapposition.h \
    mapsize.h \
    playerattitude.h \
    playerrole.h \
    ter.h \
    tertype.h

# Byte Lib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../raw/release/ -lblib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../raw/debug/ -lblib
else:unix: LIBS += -L$$OUT_PWD/../raw/ -lblib
INCLUDEPATH += $$PWD/../raw
DEPENDPATH += $$PWD/../raw
