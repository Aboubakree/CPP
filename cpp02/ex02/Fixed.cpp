#include "Fixed.hpp"

// define constructors :

Fixed::Fixed() : fixed_point(0)
{
    std::cout << "default constructor called " << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
    fixed_point = f.fixed_point;
    std::cout << "copy constructor called " << std::endl;
}
Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called " << std::endl;
    fixed_point = x << fract_bits;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called " << std::endl;
    fixed_point = (int)(roundf(x * (1 << fract_bits)));
}

Fixed::~Fixed()
{
    std::cout << "default destructor called " << std::endl;
}

// define operators :

Fixed& Fixed::operator = (const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &f)
        return *this;
    this->fixed_point = f.fixed_point;
    return *this;
}


bool Fixed::operator > (const Fixed &f) const
{
    return this->fixed_point > f.fixed_point;
}

bool Fixed::operator < (const Fixed &f) const
{
    return this->fixed_point < f.fixed_point;
}

bool Fixed::operator >= (const Fixed &f) const
{
    return this->fixed_point >= f.fixed_point;
}

bool Fixed::operator <= (const Fixed &f) const
{
    return this->fixed_point <= f.fixed_point;
}

bool Fixed::operator == (const Fixed &f) const
{
    return this->fixed_point == f.fixed_point;
}

bool Fixed::operator != (const Fixed &f) const
{
    return this->fixed_point != f.fixed_point;
}

Fixed Fixed::operator + (const Fixed &f) const
{
    Fixed   obj;
    obj.fixed_point = this->fixed_point + f.fixed_point;
    return obj;
}

Fixed Fixed::operator - (const Fixed &f) const
{
    Fixed   obj;
    obj.fixed_point = this->fixed_point - f.fixed_point;
    return obj;
}

Fixed Fixed::operator * (const Fixed &f) const
{
    Fixed   obj;
    obj.fixed_point = (this->fixed_point * f.fixed_point) >> fract_bits;
    return obj;
}

Fixed Fixed::operator / (const Fixed &f) const
{
    Fixed   obj;
    obj.fixed_point = (this->fixed_point << fract_bits) / f.fixed_point;
    return obj;
}

// Fixed& Fixed::operator ++ (int)
// {

// }

Fixed Fixed::operator ++ ()
{
    ++fixed_point;
    return *this;
}

// Fixed& Fixed::operator -- (int)
// {

// }

// Fixed Fixed::operator -- ()
// {

// }


//define member functions :

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    fixed_point = raw << fract_bits;
}


float Fixed::toFloat( void ) const
{
    return (float)fixed_point / (1 << fract_bits);
}

int Fixed::toInt( void ) const
{
    return fixed_point >> 8;
}