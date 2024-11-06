#include "PhoneBook.hpp"

void    add(PhoneBook &phonebook)
{
    Contact     contact;
    std::string input; 

    std::cout << "Enter The Contact First Name : ";
    getline(std::cin, input);
    contact.set_f_name(input);
    std::cout << "Enter The Contact Last Name : ";
    getline(std::cin, input);
    contact.set_l_name(input);
    std::cout << "Enter The Contact Nick Name : ";
    getline(std::cin, input);
    contact.set_nick_name(input);
    std::cout << "Enter The Contact Number : ";
    getline(std::cin, input);
    contact.set_number(input);
    std::cout << "Enter The Contact Secret : ";
    getline(std::cin, input);
    contact.set_secret(input);
    if (phonebook.get_size() < 8)
    {
        phonebook.add_contact(contact, phonebook.get_size());
        phonebook.reset_size();
    }
    else
    {
        phonebook.add_contact(contact, phonebook.get_old_contact());
        phonebook.reset_old_contact();
    }
    std::cout << contact.get_f_name() << " added successfully" << std::endl;
}

void put_str(std::string str)
{
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
    {
        std :: string spaces((10 - str.length()), ' ');
        std::cout << str << spaces;
    }
}

void search(PhoneBook phonebook)
{
    std::cout << "index     |" << "first name|" << "last name |" << "nickname  " << std::endl << std::endl;
    for (int i = 0; i < phonebook.get_size(); i ++)
    {
        std::cout << i << "         |";
        put_str(phonebook.get_contact(i).get_f_name());
        std::cout << "|";
        put_str(phonebook.get_contact(i).get_l_name());
        std::cout << "|";
        put_str(phonebook.get_contact(i).get_nick_name());
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void print_guide(int i)
{
    if (i == 1)
    {
        std::cout << "type : " << std::endl;
        std::cout << "ADD : to add a contact." << std::endl;
        std::cout << "SEARCH : to find a contact." << std::endl;
        std::cout << "EXIT : to exit the program." << std::endl;
    }
    else if (i == 2)
    {
        std::cout << "Looking For Contact : " << std::endl;
        std::cout << "type : " << std::endl;
        std::cout << "\"an integer from 0 --> max_int\" : to find a contact." << std::endl;
        std::cout << "-1 : to return." << std::endl;
    }
}

int main(void)
{
    PhoneBook   phonebook;
    std::string input;

    print_guide(1);
    while (true)
    {
        std::cout << "CMD--> ";
        getline(std::cin, input);
        if (input == "EXIT" || std::cin.good() == 0)
            break;
        else if (input == "ADD")
            add(phonebook);
        else if (input == "SEARCH")
            search(phonebook);
    }
    return 0;
}