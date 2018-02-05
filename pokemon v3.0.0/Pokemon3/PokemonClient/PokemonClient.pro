#-------------------------------------------------
#
# Project created by QtCreator 2016-12-07T14:59:24
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PokemonClient
TEMPLATE = app


SOURCES += main.cpp\
        pokemonclient.cpp \
    creat.cpp \
    login.cpp \
    pokemon.cpp \
    user.cpp \
    online.cpp \
    fight2.cpp \
    fight1.cpp \
    losepet.cpp

HEADERS  += pokemonclient.h \
    creat.h \
    login.h \
    pokemon.h \
    user.h \
    online.h \
    fight2.h \
    fight1.h \
    losepet.h

FORMS    += pokemonclient.ui \
    creat.ui \
    login.ui \
    pokemon.ui \
    user.ui \
    online.ui \
    fight2.ui \
    fight1.ui \
    losepet.ui

RESOURCES += \
    picture.qrc
