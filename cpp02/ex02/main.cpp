#include "Fixed.hpp"

std::ostream& operator << (std::ostream& out, const Fixed &obj)
{
    out << obj.toFloat();
    return out;
}


int main( void ) {
    Fixed  a;
    Fixed  b(0);
    std::cout << (++a) <<std::endl;
    return 0;
}