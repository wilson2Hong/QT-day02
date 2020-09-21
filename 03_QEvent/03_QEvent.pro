#-------------------------------------------------
#
# Project created by QtCreator 2019-02-20T20:29:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 03_QEvent
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mylabel.cpp \
    mybutton.cpp

HEADERS  += mywidget.h \
    mylabel.h \
    mybutton.h

FORMS    += mywidget.ui

CONFIG +=c++11
