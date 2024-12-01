#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fract_bits = 8;
        int i;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed(const int x);
        Fixed(const float x);
        Fixed& operator = (const Fixed &f);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int get_i(void) const;
        float toFloat( void ) const;
        int toInt( void ) const;
};
