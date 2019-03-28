TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    graphnode.cpp \
    mapgraph.cpp \
    matrixv2.cpp \
    consoleinterface.cpp

HEADERS += \
    priorityQueue.h \
    graphnode.h \
    utilities.h \
    mapgraph.h \
    keyvector.h \
    vector.h \
    matrixv2.h \
    consoleinterface.h
