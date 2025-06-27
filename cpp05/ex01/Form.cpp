#include "Form.hpp"

Form::Form():
_name("default"),
_gradeToSign(150),
_gradeToExecute(150),
_is_signed(false)
{
}

Form::~Form()
{
}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute):
_name(name),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute),
_is_signed(false)
{
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& obj):
_name(obj._name),
_gradeToSign(obj._gradeToSign),
_gradeToExecute(obj._gradeToExecute),
_is_signed(obj._is_signed)
{

}

Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
    {
        this->_is_signed = obj._is_signed;
    }
    return *this;
}

const std::string&   Form::getName() const
{
    return _name;
}

int                  Form::getGradeToSign() const
{
    return _gradeToSign;
}

int                  Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

bool                 Form::getIsSigned() const
{
    return _is_signed;
}

const char*    Form::GradeTooHighException::what() const throw()
{
    return "Grade To High.";
}


const char*    Form::GradeTooLowException::what() const throw()
{
    return "Grade To Low.";
}

void                 Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        bureaucrat.signForm(_name, false);
        throw Form::GradeTooLowException();
    }
    bureaucrat.signForm(_name, true);
    _is_signed = true;
}


std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    out << "Form Name      : " << obj.getName() << std::endl;
    out << "gradeTosign    : " << obj.getGradeToSign() << std::endl;
    out << "gradeToExecute : " << obj.getGradeToExecute() << std::endl;
    out << "is signed      : " << obj.getIsSigned() << std::endl;
    return out;
}