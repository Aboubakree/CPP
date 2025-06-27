#pragma once

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;
    
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, const int& grade);
    Bureaucrat(const Bureaucrat& obj);
    Bureaucrat& operator=(const Bureaucrat& obj);
    ~Bureaucrat();
    const std::string&  getName() const;
    int                 getGrade() const;
    void                incrementGrade();
    void                decrementGrade();
    void                signForm(const std::string& formName, bool ssigned) const;
	int					executeForm(AForm const & form) const;

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);