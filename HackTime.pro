QT += core gui widgets

TEMPLATE = app
TARGET = HackTime
CONFIG += c++17 utf8_source
msvc: QMAKE_CXXFLAGS += /utf-8

SOURCES += main.cpp \
           mainwindow.cpp

HEADERS += mainwindow.h \
           competition.h \
           donut.h

FORMS += mainwindow.ui

RESOURCES += resources.qrc
