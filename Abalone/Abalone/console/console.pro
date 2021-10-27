include(../default.pri)

TEMPLATE = app
CONFIG += console


LIBS += -L../lib -llibcore

SOURCES += \
    Controller.cpp \
      View.cpp \
        main.cpp

HEADERS += \
    Controller.h \
    View.h
