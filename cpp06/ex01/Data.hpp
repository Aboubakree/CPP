#pragma once
#include <iostream>

typedef struct Data
{
    int x;
    void printX()
    {
        std::cout << "x = " << x << std::endl;
    };
} Data;