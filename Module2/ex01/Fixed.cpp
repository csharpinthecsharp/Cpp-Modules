#include "Fixed.hpp"

const int Fixed::_bits = 8;

/* CONSTRUCTOR / DESTRUCTOR */
Fixed::Fixed( void ) : _value(0) {
}

Fixed::Fixed ( const Fixed& fix ) : _value(fix._value) {
} // copy constructor

Fixed::Fixed( const float cf) {

}

Fixed::Fixed( const int ci ) {
    toFloat();
}

Fixed::~Fixed( void ) {
} // destructor

Fixed &Fixed::operator=( const Fixed& fix) {
    if (this != &fix)
        setRawBits(fix.getRawBits());
    return *this;
} // copy assignement operator

/* MEMBERS FUNCTIONS */
int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits( int const raw ) {
    _value = raw;
}

float Fixed::toFloat( void ) const {
    return static_cast<float>(getRawBits());
}

int Fixed::toInt( void ) const {
    return getRawBits();
}
