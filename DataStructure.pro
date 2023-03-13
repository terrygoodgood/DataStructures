TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += main.cpp \
    linkedlist/linkedlist.cpp

HEADERS += \
    linkedlist/*.h \
    stack/*.h
