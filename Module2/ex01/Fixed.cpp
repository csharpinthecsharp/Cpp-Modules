#include "Fixed.hpp"

const int Fixed::_bits = 8;

/* CONSTRUCTOR / DESTRUCTOR */
Fixed::Fixed( void ) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed ( const Fixed& fix ) : _value(fix._value) {
    std::cout << "Copy constructor called" << std::endl;
} // copy constructor

Fixed::Fixed( const float& cf ) {
    std::cout << "Float constructor called" << std::endl;
    setRawBits(roundf(cf * (1 << _bits)));
}

Fixed::Fixed( const int& ci ) {
    std::cout << "Int constructor called" << std::endl;
    setRawBits(ci << _bits);
}

Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
} // destructor

Fixed &Fixed::operator=( const Fixed& fix ) {
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &fix)
        setRawBits(fix.getRawBits());
    return *this;
} // copy assignement operator

/* MEMBERS FUNCTIONS */
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
    return getRawBits() >> _bits;
}

std::ostream& operator<<( std::ostream& os, const Fixed& fix) {
    os << fix.toFloat();
    return os;
}
