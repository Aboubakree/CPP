#include "Fixed.hpp"


Fixed::Fixed() : fixed_point(0)
{
    std::cout << "default constructor called " << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
    fixed_point = f.fixed_point;
    std::cout << "copy constructor called " << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "default deconstructor called " << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    fixed_point = raw;
}