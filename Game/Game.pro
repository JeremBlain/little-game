#-------------------------------------------------
#
# Project created by QtCreator 2016-02-24T16:38:00
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
    render_area.cpp \
    circle.cpp \
    vec2.cpp \
    window.cpp

HEADERS  += \
    render_area.hpp \
    circle.hpp \
    vec2.hpp \
    window.hpp

FORMS    += mainwindow.ui
