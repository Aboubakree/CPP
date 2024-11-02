#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook   phonebook;
    std::string input;

    while (true)
    {
        std::cout << "CMD--> ";
        std::cin >> input;
        if (input == "EXIT" || std::cin.good() == 0)
            break;
        std::cout << "Your CMD : " << input << std::endl;
    }
    return 0;
}