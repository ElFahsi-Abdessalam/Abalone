include(../default.pri)

TEMPLATE = app
CONFIG += console


LIBS += -L../lib -llibcore

SOURCES += \
        BoardTests.cpp \
        PositionTest.cpp \
        GameTest.cpp \ 
        TestPlayer.cpp \
        main.cpp

HEADERS += \
    catch.hpp
