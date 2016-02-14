TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lboost_system -lboost_thread -lboost_filesystem

SOURCES += main.cpp \
    app.cpp \
    cleaner.cpp \
    configs.cpp

HEADERS += \
    app.h \
    cleaner.h \
    configs.h
