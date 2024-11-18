#pragma once
#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string t);
        ~Weapon();
        const std::string& getType();
        void  setType(std::string type);
};


