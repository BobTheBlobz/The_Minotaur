#-------------------------------------------------
#
# Project created by QtCreator 2018-11-19T17:32:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mino_test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        sprite.cpp \
        sprite_image.cpp \
    randomspritelinearray.cpp \
    staticsprite.cpp \
    graphicentity.cpp \
    map.cpp \
    tile.cpp \
    classfactory.cpp \
    tileempty.cpp \
    tileblock.cpp \
    character.cpp \
    engine.cpp

HEADERS += \
        mainwindow.h \
        sprite.h \
        main.h \
        sprite_image.h \
    randomspritelinearray.h \
    staticsprite.h \
    graphicentity.h \
    map.h \
    tile.h \
    classfactory.h \
    tileempty.h \
    tileblock.h \
    character.h \
    engine.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
