#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fract_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed(const int x);
        Fixed(const float x);
        Fixed& operator = (const Fixed &f);
        bool operator > (const Fixed &f) const;
        bool operator < (const Fixed &f) const;
        bool operator >= (const Fixed &f) const;
        bool operator <= (const Fixed &f) const;
        bool operator == (const Fixed &f) const;
        bool operator != (const Fixed &f) const;
        Fixed operator + (const Fixed &f) const;
        Fixed operator - (const Fixed &f) const;
        Fixed operator * (const Fixed &f) const;
        Fixed operator / (const Fixed &f) const;
        // Fixed& operator ++ (int);
        Fixed operator ++ ();
        // Fixed& operator -- (int);
        // Fixed operator -- ();
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};
