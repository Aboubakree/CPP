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
        std::string get_f_name();
        void        set_f_name(std::string f_name);
        std::string get_l_name();
        void        set_l_name(std::string l_name);
        std::string get_nick_name();
        void        set_nick_name(std::string n_name);
        std::string get_number();
        void        set_number(std::string number);
        std::string get_secret();
        void        set_secret(std::string secret);
};
