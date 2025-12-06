#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name ) {
    Zombie* newZ = new Zombie();
    _name = name;
    return newZ;
}