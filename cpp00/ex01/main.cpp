#include "main.hpp"

void    add(PhoneBook &phonebook)
{
    Contact     contact;

    if (get_contact_data(contact))
        return ;
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

void search(PhoneBook &phonebook)
{
    display_contacts(phonebook);
    if (phonebook.get_size())
        print_guide(2, phonebook);
    else
        print_guide(3, phonebook);
    std::cout << std::endl;
    if (phonebook.get_size() > 0)
        more_details(phonebook);
}


int main(void)
{
    PhoneBook   phonebook;
    std::string input;

    while (true)
    {
        clearscreen();
        print_guide(1, phonebook);
        std::cout << "CMD--> ";
        getline(std::cin, input);
        if (input == "EXIT" || std::cin.good() == 0)
            break;
        else if (input == "ADD")
            add(phonebook);
        else if (input == "SEARCH")
            search(phonebook);
        else
            std::cout << "Invalide Command !" << std::endl;
        wait_user();
    }
    return 0;
}
