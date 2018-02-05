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
    user2.cpp \
    pokemonclient2.cpp \
    pokemon2.cpp \
    online2.cpp \
    login2.cpp \
    creat2.cpp

HEADERS  += \
    user2.h \
    pokemonclient2.h \
    pokemon2.h \
    online2.h \
    login2.h \
    creat2.h

FORMS    += \
    user2.ui \
    pokemonclient2.ui \
    pokemon2.ui \
    online2.ui \
    login2.ui \
    creat2.ui

RESOURCES += \
    picture.qrc
