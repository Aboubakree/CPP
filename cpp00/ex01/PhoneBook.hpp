#pragma once

#include "main.hpp"

class PhoneBook
{
    private :
        int _size;
        int _old_contact;
        Contact contacts[8];
    public :
        PhoneBook();
        ~PhoneBook();
        int     get_size();
        void    reset_size();
        int     get_old_contact();
        void    reset_old_contact();
        void    add_contact(Contact contact, int old_contact);
        Contact get_contact(int index);
};