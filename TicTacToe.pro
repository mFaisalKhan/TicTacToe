#-------------------------------------------------
#
# Project created by QtCreator 2013-09-09T21:45:24
#
#-------------------------------------------------

QT       += testlib
QT += QtGui

TARGET = tst_tictactoetest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# tst_tictactoetest.cpp
SOURCES +=    GameModel.cpp \
    MainWindow.cpp \
    GameView.cpp \
    Controller.cpp \
    GameFactory.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ModelInterface.h \
    GameModel.h \
    MainWindow.h \
    GameViewInterface.h \
    GameView.h \
    Controller.h

FORMS += \
    MainWindow.ui
