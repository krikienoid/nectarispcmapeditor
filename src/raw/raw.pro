include(../../defaults.pri)

CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = lib

TARGET = blib

SOURCES += \
    bytearray.cpp \
    datanode.cpp

HEADERS += \
    bytearray.h \
    datanode.h \
    int.h
