#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
_name("default"),
_grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade):
_name(name),
_grade(grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj):
_name(obj._name),
_grade(obj._grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
    if (this != &obj)
    {
        _grade = obj._grade;
    }
    return *this;
}

const std::string&  Bureaucrat::getName() const
{
    return _name;
}

int                 Bureaucrat::getGrade() const
{
    return _grade;
}

void                Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade --;
}

void                Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade ++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! Maximum grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! Minimum grade is 150.";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}

