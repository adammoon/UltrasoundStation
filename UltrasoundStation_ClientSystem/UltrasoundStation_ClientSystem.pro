#-------------------------------------------------
#
# Project created by Flyfish 
#
#-------------------------------------------------

QT       += core gui

TARGET = UltrasoundStation_ClientSystem
TEMPLATE = app

#HEADER_FILE_PATH = $$PWD/Headers
#SOURCE_FILE_PATH = $$PWD/Sources
##message(HEADER_FILE_PATH)

HEADERS +=  Headers/ClientMainGui.h

SOURCES +=  Sources/ClientMainGui.cpp \
            Sources/ClientMain.cpp
