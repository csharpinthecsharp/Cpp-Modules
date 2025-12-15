#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <ostream>

class Fixed {
    private:
        int _value;
        static const int _bits;
    public:
        Fixed( void );
        explicit Fixed( const float& cf);
        explicit Fixed( const int& ci );
        explicit Fixed( const Fixed& fix ); // copy constructor
        ~Fixed( void );
        
        Fixed &operator=( const Fixed& fix); // copy assignement operator
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const& raw );
};

std::ostream& operator<<( std::ostream& os, const Fixed& fix);

#endif