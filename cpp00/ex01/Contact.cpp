#include "Contact.hpp"

Contact :: Contact(void)
{}

Contact :: ~Contact(void)
{}

std::string Contact :: get_f_name()
{
    return this->f_name;
}

void Contact :: set_f_name(std::string f_name)
{
    this->f_name = f_name;
}

std::string Contact :: get_l_name()
{
    return this->l_name;
}

void Contact :: set_l_name(std::string l_name)
{
    this->l_name = l_name;
}

std::string Contact :: get_nick_name()
{
    return this->nick_name;
}

void Contact :: set_nick_name(std::string n_name)
{
    this->nick_name = n_name;
}

std::string Contact :: get_number()
{
    return this->number;
}

void Contact :: set_number(std::string number)
{
    this->number = number;
}

std::string Contact :: get_secret()
{
    return this->secret;
}

void Contact :: set_secret(std::string secret)
{
    this->secret = secret;
}