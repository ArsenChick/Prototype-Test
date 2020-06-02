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
    ASSERT_EQ(0, 0);
}

#endif // LOAD_TEST_H
