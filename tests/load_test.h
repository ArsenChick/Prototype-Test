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
    Enemy testEnemy;
    ASSERT_EQ(1, 0);
}

#endif // LOAD_TEST_H
