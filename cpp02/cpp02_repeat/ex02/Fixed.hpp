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
	bool operator>(const Fixed& point) const;
	bool operator<(const Fixed& point) const;
	bool operator>=(const Fixed& point) const;
	bool operator<=(const Fixed& point) const;
	bool operator==(const Fixed& point) const;
	bool operator!=(const Fixed& point) const;
	Fixed operator+(const Fixed& point) const;
	Fixed operator*(const Fixed& point) const;
	Fixed operator/(const Fixed& point) const;
	Fixed operator-(const Fixed& point) const;
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);
	static Fixed& min(Fixed& obj1, Fixed& obj2);
	static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
	static Fixed& max(Fixed& obj1, Fixed& obj2);
	static const Fixed& max(const Fixed& obj1, const Fixed& obj2);
	~Fixed();
};