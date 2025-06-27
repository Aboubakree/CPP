#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm()
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
AForm("Presidential Pardon Form", 25, 5, target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj):
AForm(obj)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if(this != &obj)
	{
		AForm::operator=(obj);
	}
	return *this;
}

void		 PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
	{
		throw AForm::FormNotSigned();
	}
    if (executor.getGrade() > this->getGradeToExecute())
	{
        throw AForm::GradeTooLowException();
	}
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
