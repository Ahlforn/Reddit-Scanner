#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T00:37:44
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = RedditScanner
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    scanner.cpp \
    reddit.cpp \
    imgur.cpp

HEADERS += \
    scanner.h \
    reddit.h \
    imgur.h
