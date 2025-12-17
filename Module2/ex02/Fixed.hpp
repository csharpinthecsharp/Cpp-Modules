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
        Fixed( void ); // RULES OF THREE (1)
        Fixed( const float& cf);
        Fixed( const int& ci );
        Fixed( const Fixed& fix ); // copy constructor RULES OF THREE (2)
        Fixed &operator=( const Fixed& fix); // copy assignement operator RULES OF THREE (3)
        ~Fixed( void );
        
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits( void ) const;
        void setRawBits( int const& raw );

        /* ARITHMETIC OPERATORS */
        Fixed operator*( const Fixed& fix ) const;
        Fixed operator+( const Fixed& fix ) const;
        Fixed operator-( const Fixed& fix ) const;
        Fixed operator/( const Fixed& fix ) const;

        // PRE INCREMENT ++obj
        Fixed &operator++();
        Fixed &operator--();
        // POST INCREMENT obj++
        Fixed operator++( int );
        Fixed operator--( int ); 

        /* COMPARISON OPERATORS */
        bool operator>( const Fixed& fix ) const;
        bool operator<( const Fixed& fix) const;
        bool operator>=( const Fixed& fix ) const;
        bool operator<=( const Fixed& fix) const;
        bool operator==( const Fixed& fix ) const;
        bool operator!=( const Fixed& fix) const; // END COMPARISON OPERATORS

        static Fixed &min( Fixed& fix, Fixed& fix2 );
        static Fixed const &min ( const Fixed& fix, const Fixed& fix2 );
        static Fixed &max ( Fixed& fix, Fixed& fix2 );
        static Fixed const &max ( const Fixed& fix, const Fixed& fix2 );
};

std::ostream& operator<<( std::ostream& os, const Fixed& fix);

#endif // FIXED_HPP