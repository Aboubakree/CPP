#pragma once

#include <iostream>
#include <sstream>
#include <unistd.h>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void    clearscreen();
void    wait_user();
int     get_contact_data(Contact &contact);
void    add(PhoneBook &phonebook);
void    put_str(std::string str);
void    print_guide(int i, PhoneBook phonebook);
int     convert_index(std::string input);
void    display_contacts(PhoneBook phonebook);
void    display_details(PhoneBook phonebook,int index);
void    search(PhoneBook phonebook);
int     main(void);