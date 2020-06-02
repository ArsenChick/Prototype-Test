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
        checkPaths(level, checks, 0);

        for (int i = 0; i < LWIDTH*LHEIGHT; i++)
            ASSERT_EQ(checks[i], true);
    }
}

#endif // MAP_TEST_H
