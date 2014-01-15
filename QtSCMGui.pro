#-------------------------------------------------
#
# Project created by QtCreator 2014-01-15T12:36:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtSCMGui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    repository.cpp \
    global.cpp \
    file.cpp \
    gitrepository.cpp

HEADERS  += mainwindow.h \
    repository.h \
    global.h \
    file.h \
    gitrepository.h

FORMS    += mainwindow.ui
