#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>




int main() {
    try {
        Form forms[] = {
            Form("Form A", 100, 50),
            Form("Form B", 50, 25),
            Form("Form C", 25, 10)
        };
        
        Bureaucrat bureaucrats[] = {
            Bureaucrat("Junior", 80),
            Bureaucrat("Senior", 30),
            Bureaucrat("Manager", 15)
        };
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                try {
                    std::cout << bureaucrats[j].getName() << " attempting to sign " << forms[i].getName() << "..." << std::endl;
                    forms[i].beSigned(bureaucrats[j]);
                    std::cout << "Success!" << std::endl;
                    break;
                } catch(const std::exception& e) {
                    std::cout << "Failed: " << e.what() << std::endl;
                }
            }
            std::cout << std::endl;
        }
        
    } catch(const std::exception& e) {
        std::cerr << "Error in multiple forms test: " << e.what() << std::endl;
    }
    return 0;
}