TARGET = helper
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT  += xml
QT  -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += qml
DEFINES += TF_DLL
DESTDIR = ../lib
DEPENDPATH +=

include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
HEADERS += contentful.h
SOURCES += contentful.cpp
HEADERS += imgur.h
SOURCES += imgur.cpp
HEADERS += mediathings.h
SOURCES += mediathings.cpp
HEADERS += statistics.h
SOURCES += statistics.cpp
