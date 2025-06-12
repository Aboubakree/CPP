#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Bureaucrat Class ===" << std::endl << std::endl;

    // Test 1: Valid bureaucrat creation and basic functionality
    std::cout << "--- Test 1: Valid Bureaucrat Creation ---" << std::endl;
    try {
        Bureaucrat john("John", 200);
        std::cout << john << std::endl;
        
        // Test getters
        std::cout << "Name: " << john.getName() << std::endl;
        std::cout << "Grade: " << john.getGrade() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 2: Grade increment and decrement
    std::cout << "--- Test 2: Grade Manipulation ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 50);
        std::cout << alice << std::endl;
        
        alice.incrementGrade();  // Should become grade 49
        std::cout << alice << std::endl;
        
        alice.decrementGrade();  // Should become grade 50 again
        std::cout << alice << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 3: Exception handling - Grade too high during construction
    std::cout << "--- Test 3: Grade Too High Exception (Construction) ---" << std::endl;
    try {
        Bureaucrat invalid("TooHigh", 0);  // Should throw GradeTooHighException
        std::cout << invalid << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught general exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 4: Exception handling - Grade too low during construction
    std::cout << "--- Test 4: Grade Too Low Exception (Construction) ---" << std::endl;
    try {
        Bureaucrat invalid("TooLow", 151);  // Should throw GradeTooLowException
        std::cout << invalid << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught general exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 5: Exception handling - Grade too high during increment
    std::cout << "--- Test 5: Grade Too High Exception (Increment) ---" << std::endl;
    try {
        Bureaucrat topBureaucrat("Top", 1);
        std::cout << topBureaucrat << std::endl;
        topBureaucrat.incrementGrade();  // Should throw exception
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught GradeTooHighException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught general exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 6: Exception handling - Grade too low during decrement
    std::cout << "--- Test 6: Grade Too Low Exception (Decrement) ---" << std::endl;
    try {
        Bureaucrat worstBureaucrat("Bottom", 150);
        std::cout << worstBureaucrat << std::endl;
        worstBureaucrat.decrementGrade();  // Should throw exception
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught GradeTooLowException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught general exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 7: Copy constructor and assignment operator
    std::cout << "--- Test 7: Copy Constructor and Assignment ---" << std::endl;
    try {
        Bureaucrat original("Original", 100);
        std::cout << "Original: " << original << std::endl;
        
        // Test copy constructor
        Bureaucrat copy(original);
        std::cout << "Copy: " << copy << std::endl;
        
        // Test assignment operator
        Bureaucrat assigned("TempName", 1);
        std::cout << "Before assignment: " << assigned << std::endl;
        assigned = original;
        std::cout << "After assignment: " << assigned << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test 8: Edge cases - boundary values
    std::cout << "--- Test 8: Boundary Values ---" << std::endl;
    try {
        Bureaucrat highest("Highest", 1);
        Bureaucrat lowest("Lowest", 150);
        std::cout << highest << std::endl;
        std::cout << lowest << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== All tests completed ===" << std::endl;
    return 0;
}