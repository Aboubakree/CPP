#include <iostream>
#include <algorithm>

template <typename T>
void    easyfind(T& cont, int value)
{
    typename T::iterator it = std::find(cont.begin(), cont.end(), value);
    if (*it == value)
    {
        std::cout << "the element is fount at index : " << std::distance(cont.begin(), it) << std::endl;
        return;
    }
    throw std::runtime_error("Element not found !");
}