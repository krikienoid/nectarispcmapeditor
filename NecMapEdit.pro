TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    mainwindow.cpp \
    neclib/necmapname.cpp \
    neclib/neccoordinates.cpp \
    neclib/necmapinfo.cpp \
    neclib/byte.cpp \
    neclib/bytestring.cpp \
    neclib/necbiginfo.cpp \
    neclib/necdatamanager.cpp \
    neclib/necbigmap.cpp \
    neclib/necmapmap.cpp \
    scenemaptilegrid.cpp \
    pickermapinfo.cpp \
    editormapinfo.cpp \
    editormapmap.cpp \
    editormain.cpp \
    pickertertile.cpp \
    neclib/necter.cpp \
    pixmaptertiles.cpp \
    neclib/nectertype.cpp \
    neclib/necbigunit.cpp \
    neclib/necplayerstance.cpp \
    editorplayers.cpp \
    neclib/necplayerrole.cpp

RESOURCES += \
    necmapedit.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    mainwindow.h \
    neclib/necmapname.h \
    neclib/neccoordinates.h \
    neclib/necmapinfo.h \
    neclib/byte.h \
    neclib/bytestring.h \
    neclib/necbiginfo.h \
    neclib/necdatamanager.h \
    neclib/necbigmap.h \
    neclib/necmapmap.h \
    scenemaptilegrid.h \
    pickermapinfo.h \
    editormapmap.h \
    editormapinfo.h \
    editormain.h \
    pickertertile.h \
    neclib/necter.h \
    pixmaptertiles.h \
    neclib/nectertype.h \
    neclib/necbigunit.h \
    neclib/necplayerstance.h \
    editorplayers.h \
    neclib/necplayerrole.h

FORMS += \
    form.ui

OTHER_FILES +=
