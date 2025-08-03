#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>



int main()
{
    std::vector<int> container;
    container.push_back(0);
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    container.push_back(4);


    std::cout << "container size : " << container.size() << std::endl;
    int i = 0;
    for (std::vector<int>::iterator it = container.begin(); it != container.end(); it++)
    {
        std::cout << "vect[" << i << "] = " << *it << " | ";
        i ++;
    }
    std::cout << std::endl;
    try
    {
        easyfind(container, 5);
    } 
    catch(const std::exception& e)
    {
        std::cerr << "error : " << e.what() << std::endl;
    }
    return 0;
}