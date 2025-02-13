#pragma once
#include <iostream>

class Fixed
{
	int fixed_point;
	static const int fract_bit = 8;

public :
	Fixed();
	Fixed(const Fixed &point);
	Fixed& operator=(const Fixed& point);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	~Fixed();
};