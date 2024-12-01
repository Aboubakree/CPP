#include "Fixed.hpp"


Fixed::Fixed() : fixed_point(0), i(0)
{
    std::cout << "default constructor called " << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
    fixed_point = f.fixed_point;
    i = f.i;
    std::cout << "copy constructor called " << std::endl;
}
Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called " << std::endl;
    fixed_point = x << fract_bits;
    i = 0;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called " << std::endl;
    fixed_point = (int)(roundf(x * (1 << fract_bits)));
    i = 1;
}

Fixed::~Fixed()
{
    std::cout << "default destructor called " << std::endl;
}

Fixed& Fixed::operator = (const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &f)
        return *this;
    this->fixed_point = f.fixed_point;
    this->i = f.i;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    i = 0;
    fixed_point = raw << fract_bits;
}

int Fixed::get_i(void) const
{
    return i;
}

float Fixed::toFloat( void ) const
{
    return (float)fixed_point / (1 << fract_bits);
}

int Fixed::toInt( void ) const
{
    return fixed_point >> 8;
}

