include(../../defaults.pri)

CONFIG -= app_bundle
CONFIG -= qt

TEMPLATE = lib

TARGET = blib

SOURCES += \
    byte.cpp \
    bytestring.cpp

HEADERS += \
    byte.h \
    bytestring.h
