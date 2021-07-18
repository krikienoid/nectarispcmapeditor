include(../../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = app

SOURCES += main.cpp

# Byte Lib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../raw/release/ -lblib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../raw/debug/ -lblib
else:unix: LIBS += -L$$OUT_PWD/../raw/ -lblib
INCLUDEPATH += $$PWD/../raw
DEPENDPATH += $$PWD/../raw

# Nec Lib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../nec/release/ -lneclib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../nec/debug/ -lneclib
else:unix: LIBS += -L$$OUT_PWD/../nec/ -lneclib
INCLUDEPATH += $$PWD/../nec
DEPENDPATH += $$PWD/../nec
