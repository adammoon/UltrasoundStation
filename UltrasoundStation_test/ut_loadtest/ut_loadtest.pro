#-------------------------------------------------
#
# Project created by Flyfish
# ԪԣԵ¼
#-------------------------------------------------
TEMPLATE = app
DESTDIR = ../../../OUT/test/loadtest
TARGET = loadtest
DEPENDPATH += .
INCLUDEPATH += ../../UltrasoundStation_ClientSystem/Headers

QT += testlib
LIBS +=
CONFIG += debug

# --input
SOURCES += ut_loadTest.cpp
