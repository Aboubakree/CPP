#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string   _name;
    const int           _gradeToSign;
    const int           _gradeToExecute;
    bool                _is_signed;
public:
    Form();
    Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
    Form(const Form& obj);
    Form& operator=(const Form& obj);
    ~Form();
    const std::string&   getName() const;
    int                  getGradeToSign() const;
    int                  getGradeToExecute() const;
    bool                 getIsSigned() const;
    void                 beSigned(const Bureaucrat& bureaucrat);

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
};

std::ostream& operator<<(std::ostream& out, const Form& obj);