TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    GameMenuItem.cpp \
    GameMenu.cpp

INCLUDEPATH += -I /home/wowk/Code/raylib-2.5.0/build/src
LIBS +=  -L /home/wowk/Code/raylib-2.5.0/build/src -lGL -lraylib -ldl -lpthread -lm -lX11

HEADERS += \
    cube.h \
    GameMenuItem.h \
    GameMenu.h
