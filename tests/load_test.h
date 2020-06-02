#ifndef LOAD_TEST_H
#define LOAD_TEST_H

#include <gtest/gtest.h>
#include "test_assist.h"

extern "C++" {
#include "defines.h"
#include "map.h"
}

Map createMap (){
    Map testMap;
    return testMap;
}

TEST(loadTestNegative, nonexistentFile) {
    std::vector<int> level(LHEIGHT*LWIDTH, 0);
    ASSERT_EQ(0, 0);
    createMap().load("nonexistentFile.png",sf::Vector2u(128, 128), testlevel, LWIDTH, LHEIGHT);
    ASSERT_EQ(1, 0);
}

#endif // LOAD_TEST_H
