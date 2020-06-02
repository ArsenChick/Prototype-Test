include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES +=

HEADERS +=     \
    ../app/map.h \
    ../app/mapgenerator.h \
    ../app/defines.h \
    ../app/enemy.h \
    ../app/hero.h \
    map_test.h

SOURCES +=  main.cpp \

INCLUDEPATH += ../app
