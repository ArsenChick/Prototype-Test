#ifndef MAP_TEST_H
#define MAP_TEST_H

#include <gtest/gtest.h>
#include "test_assist.h"

extern "C++" {
#include "defines.h"
#include "mapgenerator.h"
#include "hero.h"
#include "enemy.h"
}

TEST(mapTestPositive, allReachable) {
    for (int stage = 0; stage < 5; stage++) {
        std::vector<int> level(LWIDTH*LHEIGHT, 0);

        MapGenerator mg;
        mg.levelGenerate(level);

        std::vector<bool> checks(LWIDTH*LHEIGHT, false);
        checks[0] = true;
        checkPaths(level, checks, 0);

        for (int i = 0; i < LWIDTH*LHEIGHT; i++)
            ASSERT_EQ(checks[i], true);
    }
}

TEST(mapTestPositive, enemiesReachable) {
    for (int stage = 0; stage < 5; stage++) {
        std::vector<int> level(LWIDTH*LHEIGHT, 0);

        MapGenerator mg;
        mg.levelGenerate(level);

        Hero hero;
        Enemy soldier[5];

        spawnCharacters(hero, soldier);

        for (int i = 0; i < 5; i++) {
            int hero_pos = hero.getPos();
            int enemy_pos = soldier[i].getPos();

            std::vector<bool> checks(LWIDTH*LHEIGHT, false);
            checkPaths(level, checks, hero_pos);

            ASSERT_EQ(checks[enemy_pos], true);
        }
    }
}

#endif // MAP_TEST_H
