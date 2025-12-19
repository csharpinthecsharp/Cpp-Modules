#include "Fixed.hpp"
#include "Point.hpp"

int main( int ac, char **av ) {
    /*Outside*/
    {
    Point point( 1.2f, 3.7f );
    Point a( 3.4f, 1.4f );
    Point b( 4.4f, 4.4f );
    Point c( 2.4f, 4.4f );

    if (bsp(a, b, c, point))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    }
    /*Inside*/
    {
    Point point( 3.0f, 3.0f );
    Point a( 3.0f, 1.0f );
    Point b( 4.0f, 4.0f );
    Point c( 2.0f, 4.0f );

    if (bsp(a, b, c, point))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    }
    return 0;
}