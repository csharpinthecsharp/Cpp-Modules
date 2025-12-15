#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int _bits;
    public:
        Fixed( void );
        Fixed( const float cf);
        Fixed( const int ci );
        Fixed( const Fixed& fix ); // copy constructor
        ~Fixed( void );
        
        Fixed &operator=( const Fixed& fix); // copy assignement operator
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif