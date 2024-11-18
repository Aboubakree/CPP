#include "Zombie.hpp"

int main()
{
    int N = 10;
    Zombie *z = zombieHorde(N, "Aboubakr");
    for (int i = 0; i < N; i++)
        z[i].announce();
    delete[] z;
    return 0;
}