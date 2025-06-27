#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
AForm("Shrubbery Form", 145, 137, target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj):
AForm(obj)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
	{
		AForm::operator=(obj);
	}
	return *this;
}

void		 ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == 0)
		throw AForm::FormNotSigned();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::string filename = this->getTarget() + "_shrubbery";  
    std::fstream file(filename.c_str(), std::ios::out);
    
    if (file.is_open()) 
	{
        file << "       /\\" << std::endl;
        file << "      /  \\" << std::endl;
        file << "     /    \\" << std::endl;
        file << "    /______\\" << std::endl;
        file << "     /\\    /\\" << std::endl;
        file << "    /  \\  /  \\" << std::endl;
        file << "   /____\\/____\\" << std::endl;
        file << "        ||||" << std::endl;
        file << "        ||||" << std::endl;
        file << "    ____||||____" << std::endl;
        file << std::endl;
        file.close();
        std::cout << "Shrubbery created successfully!" << std::endl;
    }
	else
        throw std::runtime_error("Could not create shrubbery file");
}