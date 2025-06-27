#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat boss("Boss", 1); 
        Bureaucrat employee("Employee", 100);
        
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("target");
        PresidentialPardonForm pardon("prisoner");
        
        std::cout << "\n--- Created Forms ---" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        
        std::cout << "\n--- Boss signing forms ---" << std::endl;
        shrub.beSigned(boss);
        robot.beSigned(boss);
        pardon.beSigned(boss);
        
        std::cout << "\n--- Boss executing forms ---" << std::endl;
        boss.executeForm(shrub);
        boss.executeForm(robot); 
        boss.executeForm(pardon); 
        

        std::cout << "\n--- Employee trying to execute ---" << std::endl;
        employee.executeForm(shrub);  
        employee.executeForm(robot);
        

        std::cout << "\n--- Unsigned form test ---" << std::endl;
        PresidentialPardonForm unsigned_form("nobody");
        boss.executeForm(unsigned_form);
        
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}