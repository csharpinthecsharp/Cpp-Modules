#include "Fixed.hpp"

const int Fixed::_bits = 8;

/* CONSTRUCTOR / DESTRUCTOR */
Fixed::Fixed( void ) : _value(0) {
}

Fixed::Fixed ( const Fixed& fix ) : _value(fix._value) {
} // copy constructor

Fixed::Fixed( const float& cf ) {
    this->setRawBits(roundf(cf * (1 << _bits)));
}

Fixed::Fixed( const int& ci ) {
    this->setRawBits(ci << _bits);
}

Fixed::~Fixed( void ) {
} // destructor
// END OF CONSTRUCTOR / DESTRUCTOR

Fixed &Fixed::operator=( const Fixed& fix ) {
    if (this != &fix)
        this->setRawBits(fix.getRawBits());
    return *this;
} // copy assignement operator

/* MEMBERS FUNCTIONS */
    /* ARITHMETIC OPERATORS */
Fixed Fixed::operator*( const Fixed& fix ) const {
    return this->toFloat() * fix.toFloat();
}

Fixed Fixed::operator+( const Fixed& fix ) const {
    return this->toFloat() + fix.toFloat();
}

Fixed Fixed::operator-( const Fixed& fix ) const {
    return this->toFloat() - fix.toFloat();
}

Fixed Fixed::operator/( const Fixed& fix ) const {
    return this->toFloat() / fix.toFloat();
}
 // END OF ARITHMETIC OPERATORS

 /* COMPARISON OPERATORS */
bool Fixed::operator>( const Fixed& fix) const {
    return this->toFloat() > fix.toFloat();
}

bool Fixed::operator<( const Fixed& fix) const {
    return this->toFloat() < fix.toFloat();
}

bool Fixed::operator>=( const Fixed& fix) const {
    return this->toFloat() >= fix.toFloat();
}

bool Fixed::operator<=( const Fixed& fix) const {
    return this->toFloat() <= fix.toFloat();
}

bool Fixed::operator==( const Fixed& fix) const {
    return this->toFloat() == fix.toFloat();
}

bool Fixed::operator!=( const Fixed& fix) const {
    return this->toFloat() != fix.toFloat();
}
 // END OF COMPARISON OPERATORS

int Fixed::getRawBits( void ) const {
    return _value;
}

void Fixed::setRawBits( int const& raw ) {
    _value = raw;
}

float Fixed::toFloat( void ) const {
    return (float)getRawBits() / (1 << _bits);
}

int Fixed::toInt( void ) const {
    return this->getRawBits() >> _bits;
}
// END OF MEMBERS FUNCTIONS

std::ostream& operator<<( std::ostream& os, const Fixed& fix) {
    os << fix.toFloat();
    return os;
}
