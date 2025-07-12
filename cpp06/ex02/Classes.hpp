#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base(){};
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base *  generate(void)
{
    srand(time(0));
    int index = rand() % 3;

    if (index == 0)
    {
        std::cout << "A is generated ." << std::endl;
        return new A();
    }
    if (index == 1)
    {
        std::cout << "B is generated ." << std::endl;
        return new B();
    }
    std::cout << "C is generated ." << std::endl;
    return new C();
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(...)
    {}
    try
    {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(...)
    {}
    try
    {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(...)
    {}
    
}