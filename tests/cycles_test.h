#ifndef CYCLES_CHECK_H
#define CYCLES_CHECK_H

#include <gtest/gtest.h>
#include "test_assist.h"

extern "C++" {
#include "mapgenerator.h"
#include "defines.h"
}

TEST(mapGeneratorTest, checkForCycles) {

    for (unsigned int passes = 0; passes < 5; ++passes) {
        std::vector<int> map(LWIDTH*LHEIGHT, 0);
        MapGenerator mg;
        mg.levelGenerate(map);

        std::vector<std::vector<int>> paths;
        paths = graph_table(map);

        std::vector<int> flags;
        /* Массив индикаторов захода в выбранную вершину */
        for (unsigned int i = 0; i < LHEIGHT*LWIDTH; ++i) {
            flags.push_back(0);
        }

        /* Вызываем поиск цикла, если он найден, отмечаем*/
        bool cycle = false;
        if (dfs(0, -1, paths, flags)) {
            cycle = true;
        }

        ASSERT_EQ(cycle, true);
    }
}
#endif // CYCLES_CHECK_H
