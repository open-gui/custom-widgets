#-------------------------------------------------
#
# Project created by QtCreator 2015-02-18T17:18:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestQCircularBr
TEMPLATE = app

INCLUDEPATH += ../QCircularBar

SOURCES += main.cpp\
        widget.cpp \
    ../QCircularBar/qcircularbar.cpp \
    ../QCircularBar/qcircularbardrawfunctions.cpp

HEADERS  += widget.h \
    ../QCircularBar/qcircularbar.h

FORMS    += widget.ui

CONFIG += mobility
MOBILITY = 

