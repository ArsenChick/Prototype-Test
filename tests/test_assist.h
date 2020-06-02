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

#endif // TEST_ASSIST_H
