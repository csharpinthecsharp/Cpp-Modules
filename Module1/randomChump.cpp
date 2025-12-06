#include "Zombie.hpp"

void Zombie::randomChump( std::string name ) {
    Zombie newZ = Zombie();
    _name = name;
    announce();
}