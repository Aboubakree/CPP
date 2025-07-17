#include <iostream>
#include "iter.hpp"


void printInt(int& element) {
    std::cout << "[" << element << "] ";
}


int main() 
{

    std::cout << "Integer array \n";
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original array: ";
    iter(intArray, intSize, print<int>);
    std::cout << "\n";
    
    std::cout << "After incrementing: ";
    iter(intArray, intSize, increment<int>);
    iter(intArray, intSize, printInt);
    std::cout << "\n\n";
    
    std::cout << "String array\n";
    std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "String array: ";
    iter(stringArray, stringSize, print<std::string>);
    
    return 0;
}