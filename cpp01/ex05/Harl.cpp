#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::debug( void )
{
    std::cout << "DEBUG : \n\
    I love having extra bacon for my 7XL-double-cheese\
    -triple-pickle-specialketchupurger. I really do!" << std::endl << std::endl;
}
void Harl::info( void )
{
    std::cout << "INFO : \n\
    I cannot believe adding extra bacon costs more money. You didn’t put\
    enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}
void Harl::warning( void )
{
    std::cout << "WARNING : \n\
    I think I deserve to have some extra bacon for free. I’ve been coming for\
    years whereas you started working here since last month." << std::endl << std::endl;
}
void Harl::error( void )
{
    std::cout << "ERROR : \nThis is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain( std::string level )
{
    int         i = 0;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*complains[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    while (i < 4)
    {
        if (levels[i] == level)
        {
            (this->*complains[i])();
            return ;
        }
        i ++;
    }
}
