include(../../defaults.pri)

# Default rules for deployment.
include(../../deployment.pri)

TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    levelinfoeditor.cpp \
    levelinfoselector.cpp \
    levelmapeditor.cpp \
    levelmapscene.cpp \
    maineditor.cpp \
    playerseditor.cpp \
    terselector.cpp \
    tertilespixmap.cpp \
    mainwindow.cpp

HEADERS += \
    levelinfoeditor.h \
    levelinfoselector.h \
    levelmapeditor.h \
    levelmapscene.h \
    maineditor.h \
    playerseditor.h \
    terselector.h \
    tertilespixmap.h \
    mainwindow.h

RESOURCES += \
    ../../necmapedit.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

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
