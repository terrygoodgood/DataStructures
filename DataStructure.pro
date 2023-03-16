TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -fexceptions
QMAKE_CXXFLAGS -= -fno-exceptions
SOURCES += main.cpp \
    public_functions.cpp
HEADERS += linkedlist/*.h stack/*.h tests.h \
    queue/QueueInterface.h \
    public_functions.h \
    queue/DoubleEndedQueue.h \
    queue/ArrayQueue.h \
    vector/vector.h
TARGET = main.exe
