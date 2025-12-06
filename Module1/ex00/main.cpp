#include "Zombie.hpp"

int main( int ac, char **av ) {
    // NOTE: FOO is allocated in the HEAP.
    // NOTE: BAR is allocated in the STACK.
    Zombie zombie = Zombie();
    // Zombies that doesn't announces themselves!
    // They need to be allocated on the heap because
    // We keep it, its being returned and we want to control it,
    // If we didn't, we would use randomChump().
    for ( int i = 0; i < 10; i++ ) {

        std::string name = "Foo";
        name += std::to_string( i );

        Zombie* foo = zombie.newZombie( name );
        zombie.announce(); // Not mandatory but keep track of the allocated one.
        delete foo;
    }

    // Zombies that does announces themselves!
    // They must be allocated on the Stack, that is 
    // Because they dont being returned, they just
    // Live shortly, announce, and vanish.
    for ( int i = 0; i < 10; i++ ) {
        std::string name = "Bar";
        name += std::to_string( i );
        
        zombie.randomChump( name );
    }
    return 0;
}