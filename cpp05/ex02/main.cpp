#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>




int main() {
    std::cout << "=== FORM CREATION TESTS ===" << std::endl;
    
    // Test 1: Valid form creation
    try {
        AForm validForm("TaxForm", 50, 25);
        std::cout << "✓ Valid form created successfully:" << std::endl;
        std::cout << validForm << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "✗ Error creating valid form: " << e.what() << std::endl;
    }
    
    // Test 2: Form with grade too high
    try {
        AForm invalidForm1("InvalidForm", 0, 50);
        std::cout << "✗ Should have thrown exception for grade too high" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "✓ Correctly caught grade too high: " << e.what() << std::endl;
    }
    
    // Test 3: Form with grade too low
    try {
        AForm invalidForm2("InvalidForm", 151, 50);
        std::cout << "✗ Should have thrown exception for grade too low" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "✓ Correctly caught grade too low: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== BUREAUCRAT CREATION TESTS ===" << std::endl;
    
    // Test 4: Valid bureaucrat creation
    try {
        Bureaucrat validBureaucrat("Alice", 30);
        std::cout << "✓ Valid bureaucrat created: " << validBureaucrat << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "✗ Error creating valid bureaucrat: " << e.what() << std::endl;
    }
    
    // Test 5: Bureaucrat with grade too high
    try {
        Bureaucrat invalidBureaucrat1("Invalid", 0);
        std::cout << "✗ Should have thrown exception for grade too high" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "✓ Correctly caught grade too high: " << e.what() << std::endl;
    }
    
    // Test 6: Bureaucrat with grade too low
    try {
        Bureaucrat invalidBureaucrat2("Invalid", 151);
        std::cout << "✗ Should have thrown exception for grade too low" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "✓ Correctly caught grade too low: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== FORM SIGNING TESTS ===" << std::endl;
    
    // Test 7: Successful form signing
    try {
        AForm f1("PermitForm", 50, 25);
        Bureaucrat b1("John", 30);
        
        std::cout << "Before signing:" << std::endl;
        std::cout << f1 << std::endl;
        std::cout << b1 << std::endl;
        
        f1.beSigned(b1);
        
        std::cout << "After signing:" << std::endl;
        std::cout << f1 << std::endl;
        
    } catch(const std::exception& e) {
        std::cerr << "✗ Error in successful signing test: " << e.what() << std::endl;
    }
    
    // Test 8: Failed form signing (grade too low)
    try {
        AForm f2("ImportantForm", 20, 10);
        Bureaucrat b2("Bob", 50);
        
        std::cout << "\nTesting form signing with insufficient grade:" << std::endl;
        std::cout << f2 << std::endl;
        std::cout << b2 << std::endl;
        
        f2.beSigned(b2);
        std::cout << "✗ Should have thrown exception for insufficient grade" << std::endl;
        
    } catch(const std::exception& e) {
        std::cout << "✓ Correctly caught insufficient grade: " << e.what() << std::endl;
        std::cout << "Form remains unsigned as expected." << std::endl;
    }
    
    // Test 9: Edge case - exact grade match
    try {
        AForm f3("EdgeForm", 75, 50);
        Bureaucrat b3("Charlie", 75);
        
        std::cout << "\n--- Edge Case: Exact Grade Match ---" << std::endl;
        std::cout << "Form requires grade " << f3.getGradeToSign() << " to sign" << std::endl;
        std::cout << "Bureaucrat has grade " << b3.getGrade() << std::endl;
        
        f3.beSigned(b3);
        std::cout << "✓ Form signed successfully with exact grade match" << std::endl;
        std::cout << "Signed status: " << (f3.getIsSigned() ? "Yes" : "No") << std::endl;
        
    } catch(const std::exception& e) {
        std::cerr << "✗ Error in edge case test: " << e.what() << std::endl;
    }
    
    // Test 10: Copy constructor and assignment
    std::cout << "\n=== COPY TESTS ===" << std::endl;
    try {
        AForm original("Original", 40, 30);
        Bureaucrat signer("Signer", 25);
        original.beSigned(signer);
        
        AForm copied(original);
        std::cout << "Original form signed status: " << original.getIsSigned() << std::endl;
        std::cout << "Copied form signed status: " << copied.getIsSigned() << std::endl;
        
        AForm assigned("Temp", 100, 100);
        assigned = original;
        std::cout << "Assigned form signed status: " << assigned.getIsSigned() << std::endl;
        
    } catch(const std::exception& e) {
        std::cerr << "Error in copy test: " << e.what() << std::endl;
    }
    
    // Test 11: Multiple forms and bureaucrats
    std::cout << "\n=== MULTIPLE FORMS TEST ===" << std::endl;
    try {
        AForm forms[] = {
            AForm("Form A", 100, 50),
            AForm("Form B", 50, 25),
            AForm("Form C", 25, 10)
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
                    std::cout << "✓ Success!" << std::endl;
                    break; // Stop trying other bureaucrats for this form
                } catch(const std::exception& e) {
                    std::cout << "✗ Failed: " << e.what() << std::endl;
                }
            }
            std::cout << std::endl;
        }
        
    } catch(const std::exception& e) {
        std::cerr << "Error in multiple forms test: " << e.what() << std::endl;
    }
    
    std::cout << "=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}