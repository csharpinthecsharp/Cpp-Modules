#include "iter.hpp"

int main( void ) {
    int eh[] = {
        0,
        1,
        2
    };
    int eh_size = 3;

    ::iter(eh, &eh_size);
    return 0;
}