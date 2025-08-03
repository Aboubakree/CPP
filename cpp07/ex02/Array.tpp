#include "Array.hpp"

template <typename T>
Array<T>::Array():arr(0),_size(0)
{}

template <typename T>
Array<T>::~Array()
{
    if (arr)
        delete[] arr;
}

template <typename T>
Array<T>::Array(const unsigned int n)
{
    arr = new T[n]();
    _size = n;
}

template <typename T>
Array<T>::Array(const Array<T>& obj):arr(0), _size(0)
{
    arr = new T[obj._size];
    _size = obj._size;
    for (size_t i = 0; i < _size; i++)
        arr[i] = obj.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
    if (this != &obj)
    {
        if (arr)
            delete[] arr;
        arr = new T[obj._size];
        _size = obj._size;
        for (size_t i = 0; i < _size; i++)
            arr[i] = obj.arr[i];
    }
    return *this;
}

template <typename T>
void Array<T>::printAll() const
{
    for (size_t i = 0; i < _size; i++)
        std::cout << "[" << i << "] = " << arr[i] << std::endl; 
}

template <typename T>
T& Array<T>::operator[](const size_t index)
{
    if (index >= _size)
        throw std::out_of_range("index out of range");
    return arr[index];
}

template <typename T>
const T& Array<T>::operator[](const size_t index) const
{
    if (index >= _size)
        throw std::out_of_range("index out of range");
    return arr[index];
}

template <typename T>
size_t      Array<T>::size() const
{
    return _size;
}