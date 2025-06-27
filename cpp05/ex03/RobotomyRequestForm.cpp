#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
AForm("Robotomy Form", 72, 45, target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : 
AForm(obj)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if(this != &obj)
	{
		AForm::operator=(obj);
	}
	return *this;
}

void		 RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
		throw AForm::FormNotSigned();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "* DRILLING NOISES *" << std::endl;
    std::cout << "GZZZZZZT! TAKK TAKK TAKK! CLANK CLANK!" << std::endl;
    
    std::srand(std::time(0));
    if (rand() % 2 == 0)
        std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy of " << this->getTarget() << " failed!" << std::endl;
}
