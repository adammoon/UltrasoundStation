#-------------------------------------------------
#
# Project created by Flyfish 
#
#-------------------------------------------------

QT       += core gui

TARGET = UltrasoundStation_ClientSystem
TEMPLATE = app
DESTDIR = ../../OUT/clientsystem

INCLUDEPATH += ../common

HEADERS +=  Headers/ClientMainGui.h \
            Headers/signinwidget.h \
            Headers/signinwidget.h \
            Headers/SignRequest.h \
            Headers/LoadReqProcessServer.h  \
            ../common/commonFunction.h    \
            ../common/QConfigManage.h \
            Headers/reporteditui.h \
            Headers/qreportmanageui.h
SOURCES +=  Sources/ClientMainGui.cpp \
            Sources/ClientMain.cpp \
            Sources/signinwidget.cpp \
            Sources/SignRequest.cpp \
            Sources/LoadReqProcessServer.cpp    \
            ../common/QConfigManage.cpp \
            Sources/reporteditui.cpp \
            Sources/qreportmanageui.cpp
#ͨ޸DEFINESϵͳĹ
DEFINES += USER_LOG_MODEL           \   #ϵͳʵû¼ģ

FORMS += \
    ui_Files/reporteditui.ui \
    ui_Files/qreportmanageui.ui
