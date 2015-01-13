TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    neclib/byte.cpp \
    neclib/bytestring.cpp \
    src/editormain.cpp \
    src/editormapinfo.cpp \
    src/editormapmap.cpp \
    src/editorplayers.cpp \
    src/pickermapinfo.cpp \
    src/pickertertile.cpp \
    src/pixmaptertiles.cpp \
    src/scenemaptilegrid.cpp \
    src/mainwindow.cpp \
    src/nec/necbiginfo.cpp \
    src/nec/necbigmap.cpp \
    src/nec/necbigunit.cpp \
    src/nec/necdatamanager.cpp \
    src/nec/neccoordinates.cpp \
    src/nec/necmapinfo.cpp \
    src/nec/necmapmap.cpp \
    src/nec/necmapname.cpp \
    src/nec/necplayerrole.cpp \
    src/nec/necplayerstance.cpp \
    src/nec/necter.cpp \
    src/nec/nectertype.cpp

RESOURCES += \
    necmapedit.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    neclib/byte.h \
    neclib/bytestring.h \
    src/editormain.h \
    src/editormapinfo.h \
    src/editormapmap.h \
    src/editorplayers.h \
    src/pickermapinfo.h \
    src/pickertertile.h \
    src/pixmaptertiles.h \
    src/scenemaptilegrid.h \
    src/mainwindow.h \
    src/nec/necbiginfo.h \
    src/nec/necbigmap.h \
    src/nec/necbigunit.h \
    src/nec/necdatamanager.h \
    src/nec/neccoordinates.h \
    src/nec/necmapinfo.h \
    src/nec/necmapmap.h \
    src/nec/necmapname.h \
    src/nec/necplayerrole.h \
    src/nec/necplayerstance.h \
    src/nec/necter.h \
    src/nec/nectertype.h

FORMS +=

OTHER_FILES +=
