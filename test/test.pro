include(../defaults.pri)

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = app

SOURCES += main.cpp

# Byte Lib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/bytes/release/ -lblib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/bytes/debug/ -lblib
else:unix: LIBS += -L$$OUT_PWD/../src/bytes/ -lblib
INCLUDEPATH += $$PWD/../src/bytes
DEPENDPATH += $$PWD/../src/bytes

# Nec Lib
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/nec/release/ -lneclib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/nec/debug/ -lneclib
else:unix: LIBS += -L$$OUT_PWD/../src/nec/ -lneclib
INCLUDEPATH += $$PWD/../src/nec
DEPENDPATH += $$PWD/../src/nec
