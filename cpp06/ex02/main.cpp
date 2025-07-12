#include <iostream>
#include "Classes.hpp"

int main()
{
    Base    *b1 = generate();

    identify(b1);
    identify(*b1);
    return 0;
}