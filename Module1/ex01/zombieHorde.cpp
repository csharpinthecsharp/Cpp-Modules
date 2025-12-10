#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    Zombie* foo = new Zombie[N];
    for (int i = 0; i < N; i++) {
        foo[i].setName( name );
        foo[i].announce( );
    }
    return (foo);
}