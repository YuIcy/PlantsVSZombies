#-------------------------------------------------
#
# Project created by QtCreator 2022-06-25T14:44:17
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlantsVSZombies
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mymenu.cpp \
    mypushbutton.cpp \
    shapedwindow.cpp \
    playscene.cpp \
    seed.cpp \
    zombies.cpp

HEADERS  += mainwindow.h \
    mymenu.h \
    mypushbutton.h \
    shapedwindow.h \
    playscene.h \
    seed.h \
    zombies.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
CONFIG += resources_big

RC_ICONS = pvz.ico
