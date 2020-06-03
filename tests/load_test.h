#ifndef LOAD_TEST_H
#define LOAD_TEST_H

#include <gtest/gtest.h>
#include "test_assist.h"

extern "C++" {
#include "defines.h"
#include "map.h"
}

TEST(loadTestNegative, nonexistentFile) {
    std::vector<int> testlevel(LHEIGHT*LWIDTH, 0);
    Map testMap;
    bool value = testMap.load("nonexistentFile.png",sf::Vector2u(128, 128), testlevel, LWIDTH, LHEIGHT);
    ASSERT_EQ(value, false);
}

#endif // LOAD_TEST_H
