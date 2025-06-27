#include "Bureaucrat.hpp"
#include <iostream>

int main() 
{
    std::cout << "--- Test : Valid Bureaucrat Creation ---" << std::endl;
    try {
        Bureaucrat john("John", 200);
        std::cout << john << std::endl;
        
        std::cout << "Name: " << john.getName() << std::endl;
        std::cout << "Grade: " << john.getGrade() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test : Grade Manipulation ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 50);
        std::cout << alice << std::endl;
        
        alice.incrementGrade();
        std::cout << alice << std::endl;
        
        alice.decrementGrade();
        std::cout << alice << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test : Grade Too High Exception (Construction) ---" << std::endl;
    try {
        Bureaucrat invalid("TooHigh", 0);  
        std::cout << invalid << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught general exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test : Grade Too Low Exception (Construction) ---" << std::endl;
    try {
        Bureaucrat invalid("TooLow", 151);  
        std::cout << invalid << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught general exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}