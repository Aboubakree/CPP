#pragma once
#include <iostream>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    ~MutantStack();
    MutantStack(const MutantStack& obj);
    MutantStack&    operator=(const MutantStack& obj);

    typedef typename std::stack<T>::container_type::iterator        iterator;
    typedef typename std::stack<T>::container_type::const_iterator  const_iterator;

    typename std::stack<T>::container_type::iterator                begin();
    typename std::stack<T>::container_type::iterator                end();
    typename std::stack<T>::container_type::const_iterator          begin() const;
    typename std::stack<T>::container_type::const_iterator          end() const;
};

#include "MutantStack.tpp"