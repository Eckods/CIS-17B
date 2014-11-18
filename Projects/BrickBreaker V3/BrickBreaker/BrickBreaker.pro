#-------------------------------------------------
#
# Project created by QtCreator 2014-09-27T14:20:03
#
#-------------------------------------------------

QT       += core gui
QT       += network

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
    GlobalScoresWindow.cpp

HEADERS  += \
    MainWindow.h \
    AboutWindow.h \
    HighScoreWindow.h \
    Paddle.h \
    Brick.h \
    NoteWindow.h \
    Ball.h \
    GlobalScoresWindow.h

FORMS    +=

RESOURCES += \
    Resources.qrc
