#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    const std::string	_target;
	bool                _is_signed;

public:
    AForm();
    AForm(const std::string& name, const int gradeToSign, const int gradeToExecute, const std::string& target);
    AForm(const AForm& obj);
    AForm& operator=(const AForm& obj);
    virtual ~AForm();
    const std::string&   getName() const;
    int                  getGradeToSign() const;
    int                  getGradeToExecute() const;
    bool                 getIsSigned() const;
	const std::string&	 getTarget() const;
    void                 beSigned(const Bureaucrat& bureaucrat);
	virtual void		 execute(Bureaucrat const & executor) const  = 0;

    class GradeTooHighException : public std::exception
    {
    public :
        const char*    what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public :
        const char*    what() const throw();
    };
    class FormNotSigned : public std::exception
    {
    public :
        const char*    what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);