#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& obj):std::stack<T>(obj)
{
}

template <typename T>
MutantStack<T>&    MutantStack<T>::operator=(const MutantStack& obj)
{
    if (this != &obj)
    {
        std::stack<T>::operator=(obj);
    }
    return *this;
}


template <typename T>
typename std::stack<T>::container_type::iterator             MutantStack<T>::begin()
{
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator             MutantStack<T>::end()
{
    return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator       MutantStack<T>::begin() const
{
    return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator       MutantStack<T>::end() const
{
    return this->c.end();
}
