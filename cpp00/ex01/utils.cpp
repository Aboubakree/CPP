#include "main.hpp"

void clearscreen() 
{
    std::cout << "\033[2J\033[H" << std::flush;
}

void wait_user()
{
    std::cout << std::endl << std::endl;
    std::cout << "Press Enter to Continue ...";
    std::cin.get();
}

int get_contact_data(Contact &contact)
{
    std::string input;

    std::cout << "Enter The Contact First Name : ";
    getline(std::cin, input);
    if (std::cin.good() == 0)
        return (std::cout << "Contact Failur" << std::endl, 1);
    contact.set_f_name(input);
    std::cout << "Enter The Contact Last Name : ";
    getline(std::cin, input);
    if (std::cin.good() == 0)
        return (std::cout << "Contact Failur" << std::endl, 1);
    contact.set_l_name(input);
    std::cout << "Enter The Contact Nick Name : ";
    getline(std::cin, input);
    if (std::cin.good() == 0)
        return (std::cout << "Contact Failur" << std::endl, 1);
    contact.set_nick_name(input);
    std::cout << "Enter The Contact Number : ";
    getline(std::cin, input);
    if (std::cin.good() == 0)
        return (std::cout << "Contact Failur" << std::endl, 1);
    contact.set_number(input);
    std::cout << "Enter The Contact Secret : ";
    getline(std::cin, input);
    if (std::cin.good() == 0)
        return (std::cout << "Contact Failur" << std::endl, 1);
    contact.set_secret(input);
    return 0;

}

void put_str(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
    {
        std :: string spaces((10 - str.length()), ' ');
        std::cout << spaces << str;
    }
}

void print_guide(int i, PhoneBook phonebook)
{
    if (i == 1)
    {
        std::cout << "        Commands :" << std::endl;
        std::cout << "ADD    : to add a contact." << std::endl;
        std::cout << "SEARCH : to find a contact." << std::endl;
        std::cout << "EXIT   : to exit the program." << std::endl<< std::endl;
    }
    else if (i == 2)
    {
        std::cout << "Looking For Contact Details  : " << std::endl;
        std::cout << "type from       [0-" << (phonebook.get_size() - 1) << "]        : to find a contact." << std::endl;
        std::cout << "type            9            : to return." << std::endl<< std::endl;
    }
    else if (i == 3)
    {
        std::cout << "Your Phone Book Is Empty     :" << std::endl;
        std::cout << "type            9            : to return." << std::endl<< std::endl;
    }
}

int convert_index(std::string input)
{
    int nb;
    std::stringstream str(input);

    str >> nb;
    if (str.fail())
        return (10);
    else 
        return (nb);
}

void display_contacts(PhoneBook phonebook)
{
    clearscreen();
    std::cout << std::endl;
    std::cout << "               Your Contacts                " << std::endl;
    std::cout << " -------------------------------------------" << std::endl;
    std::cout << "|index     |" << "first name|" << "last name |" << "nickname  |" << std::endl;
    std::cout << "|                                           |" <<std::endl;
    for (int i = 0; i < phonebook.get_size(); i ++)
    {
        std::cout << "|         " << i << "|";
        put_str(phonebook.get_contact(i).get_f_name());
        std::cout << "|";
        put_str(phonebook.get_contact(i).get_l_name());
        std::cout << "|";
        put_str(phonebook.get_contact(i).get_nick_name());
        std::cout << "|";
        std::cout << std::endl;
    }
    std::cout << " -------------------------------------------" << std::endl;
    std::cout << std::endl;
}

void display_details(PhoneBook phonebook,int index)
{
    clearscreen();
    std::cout << std::endl;
    std::cout << "               Contact Details                " << std::endl;
    std::cout << "First Name     :      " << phonebook.get_contact(index).get_f_name() << std::endl;
    std::cout << "Last  Name     :      " << phonebook.get_contact(index).get_l_name() << std::endl;
    std::cout << "Nick  Name     :      " << phonebook.get_contact(index).get_nick_name() << std::endl;
    std::cout << "Number         :      " << phonebook.get_contact(index).get_number() << std::endl;
    std::cout << "Secret         :      " << phonebook.get_contact(index).get_secret() << std::endl;
}
