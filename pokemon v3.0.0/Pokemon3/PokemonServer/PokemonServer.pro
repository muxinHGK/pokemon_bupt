#-------------------------------------------------
#
# Project created by QtCreator 2016-12-06T10:29:35
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokemonServer
TEMPLATE = app


SOURCES += main.cpp\
        pokemonserver.cpp \
    userdata.cpp

HEADERS  += pokemonserver.h \
    userdata.h

FORMS    += pokemonserver.ui

RESOURCES += \
    picture.qrc
