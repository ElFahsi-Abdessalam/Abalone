# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = gui
include(../default.pri)
TEMPLATE = app
CONFIG += qt

QT +=  widgets

LIBS += -L../lib -llibcore

HEADERS = \
    MainWindow.h \
    widget.h

SOURCES = \
 MainWindow.cpp \
 main.cpp \
 widget.cpp


#DEFINES =

DISTFILES += \
    debug/gui.exe \
    img/board.png

RESOURCES += \
    resource.qrc

FORMS += \
    MainWindow.ui \
    widget.ui


