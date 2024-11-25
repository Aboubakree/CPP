#include "Fixed.hpp"

int main()
{
    Fixed a;
    a.setRawBits(22);
    Fixed b(a);
    Fixed c;

    c = b;
    c = c;
    Fixed c(c);
    std::cout << c.getRawBits() << std::endl;
    return 0;
}

// int main( void ) {
//     Fixed a;
//     Fixed b( a );
//     Fixed c;
//     c = b;
//     std::cout << a.getRawBits() << std::endl;
//     std::cout << b.getRawBits() << std::endl;
//     std::cout << c.getRawBits() << std::endl;
//     return 0;
// }