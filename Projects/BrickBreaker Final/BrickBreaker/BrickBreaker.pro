#-------------------------------------------------
#
# Project created by QtCreator 2014-09-27T14:20:03
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql
LIBS+=-LC:\MySQL\MySQL51\lib\opt -lmysql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BrickBreaker
TEMPLATE = app


SOURCES += main.cpp\
    MainWindow.cpp \
    AboutWindow.cpp \
    HighScoreWindow.cpp \
    Paddle.cpp \
    Brick.cpp \
    NoteWindow.cpp \
    Ball.cpp \
    GlobalScoresWindow.cpp \
    GameManager.cpp

HEADERS  += \
    MainWindow.h \
    AboutWindow.h \
    HighScoreWindow.h \
    Paddle.h \
    Brick.h \
    NoteWindow.h \
    Ball.h \
    GlobalScoresWindow.h \
    GameManager.h

FORMS    +=

RESOURCES += \
    Resources.qrc
