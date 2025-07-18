#pragma once
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon      *weapon;
    public:
        HumanB(std::string n);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &p);
};
