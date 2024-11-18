#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n), weapon(NULL)
{}

HumanB::~HumanB()
{}
void HumanB::attack()
{
    if (this->weapon == NULL)
        return std::cout << "No weapen was set !" << std::endl, (void)0;
    std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &p)
{
    this->weapon = &p;
}