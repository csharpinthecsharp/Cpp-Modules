#include "Zombie.hpp"

int main( int ac, char **av ) {
    // I want to create a HORDE of FOO.
    Zombie* foo = zombieHorde( 3, "Foo 🧟" );
    // I delete the FOO Horde -> delete[] free all.
    delete[] foo;
    return 0;
}