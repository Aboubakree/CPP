#include "PhoneBook.hpp"

PhoneBook :: PhoneBook(void) : _size(0), _old_contact(0)
{}

PhoneBook :: ~PhoneBook(void)
{}

int  PhoneBook ::  get_size()
{
    return this->_size;
}

void  PhoneBook ::  reset_size()
{
    if (this->_size < 8)
        this->_size ++;
}

int  PhoneBook ::   get_old_contact()
{
    return this->_old_contact;
}

void  PhoneBook ::  reset_old_contact()
{
    if (this->_old_contact < 7)
        this->_old_contact ++;
    else
        this->_old_contact = 0;
}

void  PhoneBook ::  add_contact(Contact contact, int old_contact)
{
    this->contacts[old_contact].set_f_name(contact.get_f_name());
    this->contacts[old_contact].set_l_name(contact.get_l_name());
    this->contacts[old_contact].set_nick_name(contact.get_nick_name());
    this->contacts[old_contact].set_number(contact.get_number());
    this->contacts[old_contact].set_secret(contact.get_secret());
}

Contact PhoneBook :: get_contact(int index)
{
    return this->contacts[index];
}