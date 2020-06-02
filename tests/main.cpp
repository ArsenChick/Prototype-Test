#include <gtest/gtest.h>
//#include "map_test.h"
//#include "cycles_test.h"
#include "load_test.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
