#pragma once

#include "Contact.hpp"

class PhoneBook
{
    private :
        int _size;
        int _old_contact;
        Contact contact[8];
    public :
        PhoneBook(void);
        ~PhoneBook();
};