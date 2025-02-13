# include "Fixed.hpp"


Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &point)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point = point.fixed_point;
}

Fixed::Fixed(const int &val)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = val << fract_bit;
}

Fixed::Fixed(const float &val_flaot)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = (int)(roundf(val_flaot * (1 << fract_bit)));
}

Fixed& Fixed::operator=(const Fixed& point)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_point = point.fixed_point;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)fixed_point / (1 << fract_bit);
}

int Fixed::toInt( void ) const
{
	return fixed_point >> fract_bit;
}

