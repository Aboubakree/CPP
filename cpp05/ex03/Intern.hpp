#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
	Intern(const Intern& obj);
	Intern& operator=(const Intern& obj);
public:
	Intern();
	~Intern();
	AForm*	makeForm(const std::string& form_name,const std::string& target);
};
