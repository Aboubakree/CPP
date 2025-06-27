#include "Intern.hpp"





int main()
{ 
	AForm* form = 0;
	
	try {

		Bureaucrat boss("Boss", 1);
		Intern intern;
        std::cout << "\n--- Test : Robotomy Request ---" << std::endl;
        form = intern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        
        form->beSigned(boss);
        boss.executeForm(*form);
        delete form;
        form = 0;
        
        std::cout << "\n--- Test : Shrubbery Creation ---" << std::endl;
        form = intern.makeForm("shrubbery creation", "home");
        std::cout << *form << std::endl;
        
        form->beSigned(boss);
        boss.executeForm(*form);
        delete form;
        form = 0;
        
        std::cout << "\n--- Test : Presidential Pardon ---" << std::endl;
        form = intern.makeForm("presidential pardon", "criminal");
        std::cout << *form << std::endl;

        form->beSigned(boss);
        boss.executeForm(*form);
        delete form;
        form = 0;
        
        std::cout << "\n--- Test : Invalid Form ---" << std::endl;
        form = intern.makeForm("invalid form", "target");
        
    }
	catch (const std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
    }
	if (form) {
		delete form;
		form = 0;
	}
    
    return 0;
}