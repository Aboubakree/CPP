# include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie *z = newZombie(name);
    z->announce();
    delete z;
}