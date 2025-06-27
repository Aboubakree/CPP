#pragma once
#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	RobotomyRequestForm();
public:
	RobotomyRequestForm(const std::string& name);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();
	void		 execute(Bureaucrat const & executor) const;
};

