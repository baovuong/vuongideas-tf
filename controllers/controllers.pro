TARGET = controller
TEMPLATE = lib
CONFIG += shared c++11 x86_64
QT += network sql xml concurrent
QT -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += qml
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel

include(../appbase.pri)

HEADERS += applicationcontroller.h
SOURCES += applicationcontroller.cpp
HEADERS += blogcontroller.h
SOURCES += blogcontroller.cpp
HEADERS += homecontroller.h
SOURCES += homecontroller.cpp
HEADERS += imagecontroller.h
SOURCES += imagecontroller.cpp
HEADERS += testingcontroller.h
SOURCES += testingcontroller.cpp
HEADERS += statisticsapicontroller.h
SOURCES += statisticsapicontroller.cpp
