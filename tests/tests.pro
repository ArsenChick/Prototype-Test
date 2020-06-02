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

HEADERS +=      \
    ../app/defines.h    \
    ../app/enemy.h  \
    ../app/hero.h   \
    ../app/map.h    \
    ../app/mapgenerator.h   \
    test_assist.h   \
    map_test.h

SOURCES +=  main.cpp    \
    ../app/enemy.cpp    \
    ../app/hero.cpp \
    ../app/map.cpp  \
    ../app/mapgenerator.cpp

INCLUDEPATH += ../app
