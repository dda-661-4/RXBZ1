#-------------------------------------------------
#
# Project created by QtCreator 2018-10-04T20:40:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = rxbz
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcl.cpp \
    paint.cpp

HEADERS  += mainwindow.h \
    tcl.h \
    paint.h

FORMS    += mainwindow.ui
