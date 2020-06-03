#ifndef LOAD_TEST_H
#define LOAD_TEST_H

#include <gtest/gtest.h>
#include "test_assist.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstdio>
extern "C++" {
#include "defines.h"
#include "map.h"
}

TEST(loadTestPositive, base) {
    std::vector<int> testlevel(LHEIGHT*LWIDTH, 0);
    Map testMap;
    
    bool value = testMap.load(INPUTPATH,sf::Vector2u(128, 128), testlevel, LWIDTH, LHEIGHT);
    ASSERT_EQ(value, true);
    
}

TEST(loadTestNegative, nonexistentFile) {
    std::vector<int> testlevel(LHEIGHT*LWIDTH, 0);
    Map testMap;
    
    char *debug = (char *)malloc(sizeof(char)*128);
    snprintf(debug, 128, "file.log");
    
    int newSTDerr = open(debug, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    ASSERT_NE(newSTDerr, -1);
    int oldSTDerr = dup(STDERR_FILENO);
    close(STDERR_FILENO);
    dup2(newSTDerr, STDERR_FILENO);
    
    bool value = testMap.load("nonexistentFile.png",sf::Vector2u(128, 128), testlevel, LWIDTH, LHEIGHT);
    ASSERT_EQ(value, false);
    
    fflush(stderr);
    close(newSTDerr);
    dup2(oldSTDerr, STDERR_FILENO);

    int testFD = open(debug, O_RDONLY);
    
    char *testBuf = (char *)malloc(sizeof(char)*128);
    char *outBuf = (char *)malloc(sizeof(char)*128);
    int testCount;

    testCount = read(testFD, testBuf, 128);
    snprintf(outBuf, 128, "Failed to load image \"nonexistentFile.png\". Reason: Unable to open file\n");
    ASSERT_TRUE(testCount > 0);
    close(testFD);

    for(int i = 0; i < testCount; i++)
        ASSERT_EQ(outBuf[i], testBuf[i]);

    free(outBuf);
    free(testBuf);
    
    free(debug);
}

#endif // LOAD_TEST_H
