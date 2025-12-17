#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( Fixed( 5.05f ) - Fixed( 2 ) );
    Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
    Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );
    Fixed const f( Fixed( 5.05f ) > Fixed( 2 ) );
    Fixed const g( Fixed( 5.05f ) < Fixed( 2 ) );
    Fixed const h( Fixed( 5.05f ) >= Fixed( 2 ) );
    Fixed const i( Fixed( 5.05f ) <= Fixed( 2 ) );
    Fixed const j( Fixed( 5.05f ) == Fixed( 2 ) );
    Fixed const k( Fixed( 5.05f ) != Fixed( 2 ) );

    std::cout << "raw=" << a << std::endl;
    std::cout << "*operator=" << b << std::endl;
    std::cout << "-operator=" << c << std::endl;
    std::cout << "+operator=" << d << std::endl;
    std::cout << "/operator=" << e << std::endl;
    std::cout << ">operator=" << f << std::endl;
    std::cout << "<operator=" << g << std::endl;
    std::cout << ">=operator=" << h << std::endl;
    std::cout << "<=operator=" << i << std::endl;
    std::cout << "==operator=" << j << std::endl;
    std::cout << "!=operator=" << k << std::endl;
    std::cout << "Value without edit: " << a << std::endl;
    std::cout << "Value as pre increment " << ++a << std::endl;
    std::cout << "Value without edit: " << a<< std::endl;
    std::cout << "Value as post increment " << a++ << std::endl;
    std::cout << "Value without edit: " << a<< std::endl;
    std::cout << "Value as pre decrement " << --a << std::endl;
    std::cout << "Value without edit: " << a << std::endl;
    std::cout << "Value as post decrement " << a-- << std::endl;
    std::cout << "Value without edit: " << a << std::endl;
    return 0;
}