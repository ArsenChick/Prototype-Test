#ifndef CYCLES_CHECK_H
#define CYCLES_CHECK_H

#include <gtest/gtest.h>

extern "C++" {
#include "mapgenerator.h"
#include "defines.h"
#include "test_assist.h"
}

TEST(mapGeneratorTest, checkForCycles) {

    for (unsigned int i = 0; i < 5; ++i) {

        /* Создаем карту */
        std::vector<int> map;

        MapGenerator *mg = new MapGenerator;
        mg->levelGenerate(map);
        delete mg;

        std::vector<std::vector<int>> paths;
        /* Получаем массив содержащий смежные вершины
        * для каждой вершины из конфигов
        */
        paths = graph_table(map);

        /* Массив индикаторов захода в выбранную вершину */
        std::vector<int> flags;
        for (unsigned int i = 0; i < LHEIGHT*LWIDTH; ++i) {
            flags.push_back(0);
        }
        /* Вызываем поиск цикла, если он найден, отмечаем*/
        bool cycle = false;
        if (dfs(0, -1, paths, flags)) {
            cycle = true;
        }

        ASSERT_EQ(cycle, true);

        paths.clear();
        map.clear();
        flags.clear();
        cycle = true;
    }
}
#endif // CYCLES_CHECK_H
