TARGET = testmarkdown
TEMPLATE = app
CONFIG += console debug c++11
CONFIG -= app_bundle
QT += network sql testlib
QT -= gui
DEFINES += TF_DLL
INCLUDEPATH += ../..
LIBS += -L../../lib -lhelper -lmarkdown
include(../../appbase.pri)
SOURCES = testmarkdown.cpp      # Specifying the file name