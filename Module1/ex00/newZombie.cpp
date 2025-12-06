#include "Zombie.hpp"

Zombie* newZombie( std::string name ) { 
    Zombie* foo = new Zombie( name );
    foo->announce_heap( ); // Not mandatory but keep track of the allocated one for debug.
    return foo; 
}