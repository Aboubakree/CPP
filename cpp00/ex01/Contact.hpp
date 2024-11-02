#pragma once

#include <iostream>

class Contact
{
    private :
        std::string f_name;
        std::string l_name;
        std::string nick_name;
        std::string number;
        std::string secret;
    public :
        Contact();
        ~Contact();
};
