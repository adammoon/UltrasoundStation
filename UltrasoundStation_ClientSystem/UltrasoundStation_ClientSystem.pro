#-------------------------------------------------
#
# Project created by Flyfish 
#
#-------------------------------------------------

QT       += core gui

TARGET = UltrasoundStation_ClientSystem
TEMPLATE = app

HEADERS +=  Headers/ClientMainGui.h \
    signinwidget.h \
    Headers/signinwidget.h \
    Headers/SignRequest.h

SOURCES +=  Sources/ClientMainGui.cpp \
            Sources/ClientMain.cpp \
    Sources/signinwidget.cpp \
    Sources/SignRequest.cpp
