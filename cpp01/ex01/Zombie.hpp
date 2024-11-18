#pragma once

#include <iostream>

class  Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void set_name(std::string name);
        std::string get_name();
        void announce(void);
};

Zombie* zombieHorde( int N, std::string name );