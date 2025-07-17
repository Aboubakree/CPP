#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
    T       *arr;
    size_t  size;
public:
    Array():arr(0),size(0){};
    ~Array(){
        if (arr)
            delete[] arr;
    };
};

// #pragma once
// #include <iostream>
// #include <stdexcept>

// template <typename T>
// class Array
// {
// private:
//     T *arr;
//     size_t _size;

// public:
//     // Default constructor
//     Array() : arr(0), _size(0) {}
    
//     Parameterized constructor
//     Array(size_t n) : arr(0), _size(n) {
//         if (n > 0) {
//             arr = new T[n]();  // Initialize with default values
//         }
//     }
    
//     // Copy constructor
//     Array(const Array& other) : arr(0), _size(other._size) {
//         if (_size > 0) {
//             arr = new T[_size];
//             for (size_t i = 0; i < _size; i++) {
//                 arr[i] = other.arr[i];
//             }
//         }
//     }
    
//     // Assignment operator
//     Array& operator=(const Array& other) {
//         if (this != &other) {
//             // Clean up existing resources
//             if (arr) {
//                 delete[] arr;
//             }
            
//             // Copy from other
//             _size = other._size;
//             if (_size > 0) {
//                 arr = new T[_size];
//                 for (size_t i = 0; i < _size; i++) {
//                     arr[i] = other.arr[i];
//                 }
//             } else {
//                 arr = 0;
//             }
//         }
//         return *this;
//     }
    
//     // Destructor
//     ~Array() {
//         if (arr) {
//             delete[] arr;  // Use delete[] for arrays
//         }
//     }
    
//     Subscript operator
//     T& operator[](size_t index) {
//         if (index >= _size) {
//             throw std::out_of_range("Index out of bounds");
//         }
//         return arr[index];
//     }
    
//     // Const subscript operator
//     const T& operator[](size_t index) const {
//         if (index >= _size) {
//             throw std::out_of_range("Index out of bounds");
//         }
//         return arr[index];
//     }
    
//     // Size getter
//     size_t size() const {
//         return _size;
//     }
// };