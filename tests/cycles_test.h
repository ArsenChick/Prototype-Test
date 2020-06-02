#ifndef CYCLES_CHECK_H
#define CYCLES_CHECK_H

#include <gtest/gtest.h>
#include "test_assist.h"

extern "C++" {
#include "mapgenerator.h"
#include "defines.h"
}

TEST(mapGeneratorTest, checkForCycles) {

    std::vector<int> map(LWIDTH*LHEIGHT, 0);
    std::vector<int> flags;
    bool cycle;
    std::cerr << "[          ] starting cycle" << std::endl;
    for (unsigned int passes = 0; passes < 5; ++passes) {
        std::cerr << "[          ] pre-generation" << std::endl;
        MapGenerator mg;
        mg.levelGenerate(map);

        std::cerr << "[          ] generated map" << std::endl;
        std::vector<std::vector<int>> paths;
        paths = graph_table(map);
        std::cerr << "[          ] paths vector:" << std::endl;
        for (unsigned int start = 0; start < LWIDTH*LHEIGHT; ++start)
        {
            for (unsigned int start_2 = 0; start_2 < paths[start].size(); ++start_2)
                std::cerr << paths[start][start_2] << " ";
            std::cerr << std::endl;
        }

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

        std::cerr << "[          ] cycle detected: " << cycle << std::endl;
        std::cerr << "[          ] for: " << passes + 1 << "time" << std::endl;

        ASSERT_EQ(cycle, true);

        paths.clear();
        map.clear();
        flags.clear();
        std::cerr << "[          ] vectors cleared" << std::endl;
    }
}
#endif // CYCLES_CHECK_H
