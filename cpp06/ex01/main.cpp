#include <iostream>
#include <iomanip>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    std::cout << "=== Serializer Test ===" << std::endl;
    
    // Create a Data object
    Data* originalPtr = new Data(42, "Test Object", 3.14159);
    
    std::cout << "Original Data object:" << std::endl;
    originalPtr->display();
    std::cout << "Original pointer address: " << originalPtr << std::endl;
    
    // Serialize the pointer
    uintptr_t serialized = Serializer::serialize(originalPtr);
    std::cout << "Serialized value: 0x" << std::hex << serialized << std::dec << std::endl;
    
    // Deserialize back to pointer
    Data* deserializedPtr = Serializer::deserialize(serialized);
    std::cout << "Deserialized pointer address: " << deserializedPtr << std::endl;
    
    // Test if they are equal
    if (originalPtr == deserializedPtr) {
        std::cout << "✓ Success: Pointers are equal!" << std::endl;
    } else {
        std::cout << "✗ Error: Pointers are not equal!" << std::endl;
    }
    
    // Test that deserialized pointer still points to valid data
    std::cout << "Data from deserialized pointer:" << std::endl;
    deserializedPtr->display();
    
    // Test with null pointer
    std::cout << "\n=== Null Pointer Test ===" << std::endl;
    Data* nullPtr = nullptr;
    uintptr_t serializedNull = Serializer::serialize(nullPtr);
    Data* deserializedNull = Serializer::deserialize(serializedNull);
    
    std::cout << "Original null pointer: " << nullPtr << std::endl;
    std::cout << "Serialized null: 0x" << std::hex << serializedNull << std::dec << std::endl;
    std::cout << "Deserialized null: " << deserializedNull << std::endl;
    
    if (nullPtr == deserializedNull) {
        std::cout << "✓ Success: Null pointer test passed!" << std::endl;
    } else {
        std::cout << "✗ Error: Null pointer test failed!" << std::endl;
    }
    
    // Clean up
    delete originalPtr;
    
    return 0;
}