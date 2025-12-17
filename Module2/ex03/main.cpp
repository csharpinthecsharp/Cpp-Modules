#include "Fixed.hpp"
#include "Point.hpp"

int main( int ac, char **av ) {
    Point point( 3.0f, 3.0f );
    Point a( 3.0f, 1.0f );
    Point b( 4.0f, 4.0f );
    Point c( 2.0f, 4.0f );

    if (bsp(a, b, c, point))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    return 0;
}