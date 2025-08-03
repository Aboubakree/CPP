#include "Span.hpp"

Span::Span(unsigned int N):_MAXSIZE(N)
{
}

Span::~Span()
{
}


Span::Span(const Span& sp):
_container(sp._container),
_MAXSIZE(sp._MAXSIZE)
{}

Span&               Span::operator=(const Span& sp)
{
    if (this != &sp)
    {
        _container = sp._container;
        _MAXSIZE = sp._MAXSIZE;
    }
    return *this;
}

void        Span::addNumber(int nbr)
{
    if (_container.size() >= _MAXSIZE)
        throw std::runtime_error("You exceeded the max size");
    _container.push_back(nbr);
}

void        Span::addNumbers(std::vector <int>::iterator begin, std::vector <int>::iterator end)
{
    if (_container.size() + std::distance(begin, end) > _MAXSIZE)
        throw std::runtime_error("Can't add this sequence of numbers cause has exceeded the max size !");
    _container.insert(_container.begin() + _container.size(), begin, end);
}

void        Span::printSpan()
{
    for (std::vector<int> :: iterator it = _container.begin(); it != _container.end(); it ++)
        std::cout << "span(" << std::distance(_container.begin(), it) << ") = " << *it << std::endl;
}

std::vector<int>    Span::getDistances()
{
    if (_container.size() < 2)
        throw std::runtime_error("Not enough element in the span !");
    std::vector <int> distance;
    for (std::vector<int>::iterator it1 = _container.begin(); it1 != _container.end() - 1; it1 ++)
    {
        for (std::vector<int>::iterator it2 = it1 + 1; it2 !=_container.end(); it2 ++ )
            distance.push_back(std::abs(*it1 - *it2));
    }
    return distance;
}

int         Span::shortestSpan()
{
    std::vector <int> distance = getDistances();
    return *(std::min_element(distance.begin(), distance.end()));
}

int         Span::longestSpan()
{
    std::vector <int> distance = getDistances();
    return *(std::max_element(distance.begin(), distance.end()));
}