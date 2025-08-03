#pragma once
#include <iostream>
#include <exception>
#include <cstdlib>



template <typename T>
class Array
{
private:
    T       *arr;
    size_t  _size;
    
public:
    Array();
    ~Array();
    Array(const unsigned int n);
    Array(const Array<T>& obj);
    Array<T>&   operator=(const Array<T>& obj);
    T&          operator[](const size_t index);
    const T&    operator[](const size_t index) const;
    size_t      size() const;
    void        printAll() const;

};

#include "Array.tpp"