#-------------------------------------------------
#
# Project created by Flyfish 
#
#-------------------------------------------------

QT       += core gui

TARGET = UltrasoundStation_ClientSystem
TEMPLATE = app
DESTDIR = ../../OUT/clientsystem
HEADERS +=  Headers/ClientMainGui.h \
    signinwidget.h \
    Headers/signinwidget.h \
    Headers/SignRequest.h \
    ../common/commonFunction.h \
    Headers/LoadReqProcessServer.h

SOURCES +=  Sources/ClientMainGui.cpp \
            Sources/ClientMain.cpp \
    Sources/signinwidget.cpp \
    Sources/SignRequest.cpp \
    Sources/LoadReqProcessServer.cpp
#通过修改DEFINES变量来定制系统的功能
DEFINES += USER_LOG_MODEL           \   #该系统实现了用户登录管理模块
