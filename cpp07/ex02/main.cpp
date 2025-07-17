#include "Array.hpp"

int main()
{
    Array<int> arr;
    (void)arr;
    return 0;
}

// #include "Array.hpp"
// // #include <iostream>

// int main() {
//     try {
//         // Test default constructor
//         std::cout << "=== Testing Default Constructor ===\n";
//         Array<int> arr1;
//         std::cout << "Default array size: " << arr1.size() << std::endl;
        
//         // Test parameterized constructor
//         std::cout << "\n=== Testing Parameterized Constructor ===\n";
//         Array<int> arr2(5);
//         std::cout << "Array size: " << arr2.size() << std::endl;
        
//         // Fill array with values
//         for (size_t i = 0; i < arr2.size(); i++) {
//             arr2[i] = i * 10;
//         }
        
//         // Display array contents
//         std::cout << "Array contents: ";
//         for (size_t i = 0; i < arr2.size(); i++) {
//             std::cout << arr2[i] << " ";
//         }
//         std::cout << std::endl;
        
//         // Test copy constructor
//         std::cout << "\n=== Testing Copy Constructor ===\n";
//         Array<int> arr3(arr2);
//         std::cout << "Copied array size: " << arr3.size() << std::endl;
//         std::cout << "Copied array contents: ";
//         for (size_t i = 0; i < arr3.size(); i++) {
//             std::cout << arr3[i] << " ";
//         }
//         std::cout << std::endl;
        
//         // Test assignment operator
//         std::cout << "\n=== Testing Assignment Operator ===\n";
//         Array<int> arr4;
//         arr4 = arr2;
//         std::cout << "Assigned array size: " << arr4.size() << std::endl;
//         std::cout << "Assigned array contents: ";
//         for (size_t i = 0; i < arr4.size(); i++) {
//             std::cout << arr4[i] << " ";
//         }
//         std::cout << std::endl;
        
//         // Test with different type
//         std::cout << "\n=== Testing with Double ===\n";
//         Array<double> doubleArr(3);
//         doubleArr[0] = 1.1;
//         doubleArr[1] = 2.2;
//         doubleArr[2] = 3.3;
        
//         std::cout << "Double array contents: ";
//         for (size_t i = 0; i < doubleArr.size(); i++) {
//             std::cout << doubleArr[i] << " ";
//         }
//         std::cout << std::endl;
        
//         // Test bounds checking
//         std::cout << "\n=== Testing Bounds Checking ===\n";
//         try {
//             std::cout << "Accessing valid index [1]: " << arr2[1] << std::endl;
//             std::cout << "Accessing invalid index [10]: " << arr2[10] << std::endl;
//         } catch (const std::out_of_range& e) {
//             std::cout << "Exception caught: " << e.what() << std::endl;
//         }
        
//     } catch (const std::exception& e) {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
    
//     return 0;
// }