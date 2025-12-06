#include "Zombie.hpp"

Zombie::Zombie( void ) { 
}

Zombie::~Zombie( void ) {
    std::cout << _name << " Destroyed!" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}