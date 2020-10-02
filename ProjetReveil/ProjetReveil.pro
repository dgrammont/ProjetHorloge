TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Clavier.cpp \
        cadran.cpp \
        horloge.cpp \
        main.cpp \
        reveil.cpp \
        sonnerie.cpp

HEADERS += \
    Clavier.h \
    cadran.h \
    horloge.h \
    reveil.h \
    sonnerie.h
