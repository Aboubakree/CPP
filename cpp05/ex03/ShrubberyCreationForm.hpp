#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
private:
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm();
	void		 execute(Bureaucrat const & executor) const;
};

