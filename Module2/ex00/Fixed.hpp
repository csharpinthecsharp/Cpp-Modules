#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        int _fix_point;
        static const int _bits;
    public:
        Fixed( void ); // Default Constructor
        Fixed( const Fixed& fix ); // Copy constructor
        ~Fixed( void ); // Destructor

        Fixed &operator=( const Fixed& fix ); // Copy assignement operator
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif