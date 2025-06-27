#include "AForm.hpp"

AForm::AForm():
_name("default"),
_gradeToSign(150),
_gradeToExecute(150),
_target("none"),
_is_signed(false)
{
}

AForm::~AForm()
{
}

AForm::AForm(const std::string& name, const int gradeToSign, const int gradeToExecute, const std::string& target):
_name(name),
_gradeToSign(gradeToSign),
_gradeToExecute(gradeToExecute),
_target(target),
_is_signed(false)
{
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& obj):
_name(obj._name),
_gradeToSign(obj._gradeToSign),
_gradeToExecute(obj._gradeToExecute),
_target(obj._target),
_is_signed(obj._is_signed)
{

}

AForm& AForm::operator=(const AForm& obj)
{
    if (this != &obj)
    {
        this->_is_signed = obj._is_signed;
    }
    return *this;
}

const std::string&   AForm::getName() const
{
    return _name;
}

int                  AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int                  AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

bool                 AForm::getIsSigned() const
{
    return _is_signed;
}

const std::string&	 AForm::getTarget() const
{
	return _target;
}

const char*    AForm::GradeTooHighException::what() const throw()
{
    return "Grade To High.";
}


const char*    AForm::GradeTooLowException::what() const throw()
{
    return "Grade To Low.";
}

const char*    AForm::FormNotSigned::what() const throw()
{
    return "The Form is not signed !";
}

void                 AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
        bureaucrat.signForm(_name, false);
        throw AForm::GradeTooLowException();
    }
    bureaucrat.signForm(_name, true);
    _is_signed = true;
}


std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    out << "Form Name      : " << obj.getName() << std::endl;
    out << "gradeTosign    : " << obj.getGradeToSign() << std::endl;
    out << "gradeToExecute : " << obj.getGradeToExecute() << std::endl;
    out << "is signed      : " << obj.getIsSigned() << std::endl;
    return out;
}