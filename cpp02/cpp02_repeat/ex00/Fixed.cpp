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
