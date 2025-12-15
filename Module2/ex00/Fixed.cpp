#include "Fixed.hpp"

const int Fixed::_fract_bits = 8;

Fixed::Fixed( void ) : _fix_point(0) {
    std::cout << "Default constructor called." << std::endl;   
} // Constructor

Fixed::Fixed( const Fixed& fix) : _fix_point(fix._fix_point) {
    std::cout << "Copy constructor called" << std::endl;
} // Constructor

Fixed::~Fixed( void ) {
    std::cout << "Destructor called." << std::endl;
}

Fixed &Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        setRawBits(f.getRawBits());
    return *this;
} // Not a Constructor

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _fix_point;
}

void Fixed::setRawBits( int const raw ) {
    _fix_point = raw;
}