#ifndef LOAD_TEST_H
#define LOAD_TEST_H

#include <gtest/gtest.h>
#include "test_assist.h"

extern "C++" {
#include "defines.h"
#include "map.h"
#include "hero.h"
#include "enemy.h"
}

TEST(loadTestNegative, nonexistentFile) {
    ASSERT_EQ(1, 0);
    Map testMap;
    std::vector<int> testLevel(LHEIGHT*LWIDTH, 0);
    std::cout << "Сделал вектор" << std::endl;
    bool value = testMap.load("nonexistent.png",sf::Vector2u(128, 128), testLevel, LWIDTH, LHEIGHT);
    std::cout << "Загрузил несуществующее" << std::endl;
    ASSERT_EQ(value, false);
}

#endif // LOAD_TEST_H
