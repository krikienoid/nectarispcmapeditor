include(../defaults.pri)

# Default rules for deployment.
include(../deployment.pri)

TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    editormain.cpp \
    editormapinfo.cpp \
    editormapmap.cpp \
    editorplayers.cpp \
    pickermapinfo.cpp \
    pickertertile.cpp \
    pixmaptertiles.cpp \
    scenemaptilegrid.cpp \
    mainwindow.cpp

HEADERS += \
    editormain.h \
    editormapinfo.h \
    editormapmap.h \
    editorplayers.h \
    pickermapinfo.h \
    pickertertile.h \
    pixmaptertiles.h \
    scenemaptilegrid.h \
    mainwindow.h

RESOURCES += \
    ../necmapedit.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
#QML_IMPORT_PATH =

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
