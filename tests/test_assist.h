#ifndef TEST_ASSIST_H
#define TEST_ASSIST_H

#include <vector>
#include <chrono>
#include <random>

extern "C++" {
#include "defines.h"
#include "hero.h"
#include "enemy.h"
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

// Original lines from main.cpp
void spawnCharacters(Hero &hero, Enemy* soldier)
{
    std::mt19937 gen;
    auto now = std::chrono::high_resolution_clock::now();
    gen.seed(now.time_since_epoch().count());

    int hero_pos = gen() % (LHEIGHT*LWIDTH);
    hero.setStartPosition(hero_pos);

    int row = hero_pos / LWIDTH;
    int col = hero_pos % LWIDTH;

    for (int i = 0; i < 5; i++) {
        int enemy_col, enemy_row;

        while(true) {
            enemy_col = gen() % LWIDTH;
            enemy_row = gen() % LHEIGHT;
            if ((enemy_col < col - 1 || enemy_col > col + 1) &&
                (enemy_row < row - 1 || enemy_row > row + 1))
                break;
        }

        int enemy_pos = enemy_row * LWIDTH + enemy_col;
        soldier[i].setStartPosition(enemy_pos);
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
