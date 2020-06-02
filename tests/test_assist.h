#ifndef TEST_ASSIST_H
#define TEST_ASSIST_H

#include <vector>

extern "C++" {
#include "defines.h"
}

void checkPaths(std::vector<int> &tiles, std::vector<bool> &paths, int pos)
{
    int row = pos / LWIDTH;
    int col = pos % LWIDTH;
    int newpos;

    newpos = pos - LWIDTH;
    if((row - 1 >= 0) && (paths[newpos] != true) &&
            ((tiles[pos] & ROUTEUP) != 0) &&
            ((tiles[newpos] & ROUTEDOWN) != 0)) {

        paths[newpos] = true;
        checkPaths(tiles, paths, newpos);
    }

    newpos = pos + LWIDTH;
    if((row + 1 < LHEIGHT) && (paths[newpos] != true) &&
            ((tiles[pos] & ROUTEDOWN) != 0) &&
            ((tiles[newpos] & ROUTEUP) != 0)) {

        paths[newpos] = true;
        checkPaths(tiles, paths, newpos);
    }

    newpos = pos - 1;
    if((col - 1 >= 0) && (paths[newpos] != true) &&
            ((tiles[pos] & ROUTELEFT) != 0) &&
            ((tiles[newpos] & ROUTERIGHT) != 0)) {

        paths[newpos] = true;
        checkPaths(tiles, paths, newpos);
    }

    newpos = pos + 1;
    if((col + 1 < LWIDTH) && (paths[newpos] != true) &&
            ((tiles[pos] & ROUTERIGHT) != 0) &&
            ((tiles[newpos] & ROUTELEFT) != 0)) {

        paths[newpos] = true;
        checkPaths(tiles, paths, newpos);
    }
}

std::vector<std::vector<int>> graph_table(std::vector<int> map) {
    std::vector<std::vector<int>> result;

    for (unsigned int i = 0; i < LHEIGHT*LWIDTH; ++i) {
        std::vector<int> sup;
        result.push_back(sup);
    }

    for (unsigned int i = 0; i < LHEIGHT*LWIDTH; ++i) {
        if (map[i] && ROUTEUP != 0)
            result[i].push_back(i - LWIDTH);
        if (map[i] && ROUTELEFT != 0)
            result[i].push_back(i - 1);
        if (map[i] && ROUTEDOWN != 0)
            result[i].push_back(i + LWIDTH);
        if (map[i] && ROUTERIGHT != 0)
            result[i].push_back(i + 1);
    }

    return result;
}

bool dfs(int v, int prev, std::vector<std::vector<int>> &paths, std::vector<int> &flags) {
    flags[v] = 1;
    for (unsigned int i = 0; i < paths[v].size(); ++i) {
        int way = paths[v][i];
        if (way != prev) {
            if (flags[way] == 1)
                return true;
            if (flags[way] == 0)
                if (dfs(way, v, paths, flags))
                    return true;
        }
    }
    flags[v] = 2;
    return false;
}

#endif // TEST_ASSIST_H
