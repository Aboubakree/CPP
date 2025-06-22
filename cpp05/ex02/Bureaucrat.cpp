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
_name(name)
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

void                Bureaucrat::signForm(const std::string& formName, bool ssigned) const
{
    if (ssigned)
        std::cout << _name << " signed " << formName << std::endl;
    else
        std::cout << _name << " couldn’t sign " << formName << " because its Grade is Too Low !" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high! Minimum grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low! Maximum grade is 150.";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return out;
}

