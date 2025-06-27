#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(const Intern& obj)
{
	(void)obj;
}
Intern& Intern::operator=(const Intern& obj)
{
	(void)obj;
	return *this;
}

static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPardon(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& form_name, const std::string& target)
{
    std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (*creators[])(const std::string&) = {
        createShrubbery,
        createRobotomy,
        createPardon
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (names[i] == form_name)
        {
            std::cout << "Intern creates " << form_name << std::endl;
            return creators[i](target);
        }
    }
    
    std::cout << "Intern couldn't create " << form_name 
              << " because this form doesn't exist" << std::endl;
	return 0;
}
