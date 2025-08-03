#include "Span.hpp"



int main()
{
    Span sp = Span(5);
    try
    {
        sp.addNumber(11);
        std::vector <int> v;
        v.push_back(6);
        v.push_back(17);
        v.push_back(3);
        sp.addNumbers(v.begin(), v.end());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Span sp1(sp);
    try
    {
        sp1.addNumber(9);
        sp1.printSpan();
        std::cout << "longest  Span : " << sp1.longestSpan() << std::endl;
        std::cout << "shortest Span : " << sp1.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}