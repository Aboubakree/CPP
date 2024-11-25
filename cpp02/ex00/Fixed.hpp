#pragma once

#include <iostream>

class Fixed
{
    private:
        int fixed_point;
        static const int fract_bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &f);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};
