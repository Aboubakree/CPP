#pragma once
#include <iostream>
#include <vector>
#include <algorithm>



class Span
{
private:
    std::vector <int>   _container;
    unsigned int        _MAXSIZE;
    Span();
public:
    Span(unsigned int N);
    Span(const Span& sp);
    ~Span();
    Span&               operator=(const Span& sp);
    void                addNumber(int nbr);
    void                addNumbers(std::vector <int>::iterator begin, std::vector <int>::iterator end);
    void                printSpan();
    std::vector<int>    getDistances();
    int                 shortestSpan();
    int                 longestSpan();
};