#ifndef CYCLES_CHECK_H
#define CYCLES_CHECK_H

#include <gtest/gtest.h>

extern "C++" {
#include "mapgenerator.h"
#include "defines.h"
#include "test_assist.h"
}

TEST(mapGeneratorTest, checkForCycles) {

    std::vector<int> map;
    std::vector<std::vector<int>> paths;
    std::vector<int> flags;
    bool cycle;
    for (unsigned int passes = 0; passes < 5; ++passes) {

        MapGenerator *mg = new MapGenerator;
        mg->levelGenerate(map);
        delete mg;
        std::cerr << "[          ] generated map" << std::endl;
        paths = graph_table(map);

        /* Массив индикаторов захода в выбранную вершину */
        for (unsigned int i = 0; i < LHEIGHT*LWIDTH; ++i) {
            flags.push_back(0);
        }
        std::cerr << "[          ] dfs started" << std::endl;
        /* Вызываем поиск цикла, если он найден, отмечаем*/
        cycle = false;
        if (dfs(0, -1, paths, flags)) {
            cycle = true;
        }

        std::cerr << "[          ] cycle detected" << std::endl;
        std::cerr << "[          ] for: " << passes + 1 << "time" << std::endl;

        ASSERT_EQ(cycle, true);

        paths.clear();
        map.clear();
        flags.clear();
        std::cerr << "[          ] vectors cleared" << std::endl;
    }
}
#endif // CYCLES_CHECK_H
