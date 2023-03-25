TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -fexceptions
QMAKE_CXXFLAGS -= -fno-exceptions
SOURCES += main.cpp \
    public_functions.cpp \
    main.cpp \
    public_functions.cpp
HEADERS += linkedlist/*.h stack/*.h tests.h \
    queue/QueueInterface.h \
    public_functions.h \
    queue/DoubleEndedQueue.h \
    queue/ArrayQueue.h \
    vector/vector.h \
    vector/nodelist.h \
    vector/nodesequence.h \
    linkedlist/clinkedlist.h \
    linkedlist/dlinkedlist.h \
    linkedlist/glinkedlist.h \
    linkedlist/linkedlist.h \
    queue/ArrayQueue.h \
    queue/DoubleEndedQueue.h \
    queue/QueueInterface.h \
    stack/lstack.h \
    stack/stack.h \
    vector/nodelist.h \
    vector/nodesequence.h \
    vector/vector.h \
    public_functions.h \
    tests.h \
TARGET =
