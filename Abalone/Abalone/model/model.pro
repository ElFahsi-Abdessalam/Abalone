include(../default.pri)

TEMPLATE = lib
TARGET = libcore
DESTDIR = ../lib

SOURCES += \
     Game.cpp \
     Player.cpp \
     Position.cpp \
     AbaPro.cpp \
     Board.cpp

HEADERS += \
   AbaPro.h \
   Board.h \
   Case.h \
   Color.h \
   Direction.h \
   Game.h \
   Player.h \
   PlayerStatus.h \
   Position.h
