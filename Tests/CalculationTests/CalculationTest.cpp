// CalculationTest.cpp : Defines the entry point for the console application.
// see http://www.yolinux.com/TUTORIALS/Cpp-GoogleTest.html#EXAMPLE

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include <limits.h> 
#include <gtest/gtest.h>

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

