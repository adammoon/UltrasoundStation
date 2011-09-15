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
            ../common/QFilterFactory.h\
            Headers/reporteditui.h \
            Headers/qreportmanageui.h \
            ../common/QAbstractFilter.h \
	    ../common/QMatrix.h \
	    ../common/qbezier.h \
    ../common/qbezier.h
SOURCES +=  Sources/ClientMainGui.cpp \
            Sources/ClientMain.cpp \
            Sources/signinwidget.cpp \
            Sources/SignRequest.cpp \
            Sources/LoadReqProcessServer.cpp    \
            ../common/QConfigManage.cpp \
            ../common/QFilterFactory.cpp\
            Sources/reporteditui.cpp \
            Sources/qreportmanageui.cpp \
    ../common/QAbstractFilter.cpp \
    ../common/QMatrix.cpp \
    ../common/qbezier.cpp
#ͨ޸DEFINESϵͳĹ
DEFINES += USER_LOG_MODEL           \   #ϵͳʵû¼ģ

FORMS += \
    ui_Files/reporteditui.ui \
    ui_Files/qreportmanageui.ui
