#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed b(a);
    a = a;
    a = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;

    a.setRawBits(100);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;

    b = a;
    std::cout << b.getRawBits() << std::endl;
    Fixed c(b);
    std::cout << c.getRawBits() << std::endl;

    c.setRawBits(2);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}