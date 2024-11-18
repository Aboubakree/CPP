#include "Zombie.hpp"

Zombie::Zombie()
{}

Zombie::~Zombie()
{
    std::cout << this->get_name() << ": By From Destroctor !" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

std::string Zombie::get_name()
{
    return this->name ;
}