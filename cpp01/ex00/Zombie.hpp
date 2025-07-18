#pragma once

#include <iostream>

class  Zombie
{
    private:
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void set_name(std::string name);
        std::string get_name();
        void announce(void);
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );