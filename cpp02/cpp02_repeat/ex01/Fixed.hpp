#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	int fixed_point;
	static const int fract_bit = 8;

public :
	Fixed();
	Fixed(const Fixed &point);
	Fixed(const int &val_int);
	Fixed(const float &val_flaot);
	Fixed& operator=(const Fixed& point);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	~Fixed();
};