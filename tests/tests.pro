include(gtest_dependency.pri)

#mytarget.commands = export LD_LIBRARY_PATH=$$PWD/../external/SFML-2.5.1/lib

#QMAKE_EXTRA_TARGETS += mytarget
#POST_TARGETDEPS += mytarget

LIBS += -L$$PWD/../external/SFML-2.5.1/lib

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += $$PWD/../external/SFML-2.5.1/include
DEPENDPATH += $$PWD/../external/SFML-2.5.1/include

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
