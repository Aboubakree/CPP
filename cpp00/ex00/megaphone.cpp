#include <iostream>


class A
{
    public :
        static int x;
    private :
        static int y;
    protected :
        static int z;
};

namespace test
{
    int x = 10;
}

int x = 20;


int main()
{
    int x = 30;
    std::cout<<test::x<< std::endl;
    std::cout<<::x<< std::endl;
    std::cout<<x<< std::endl;
    return 0;
}