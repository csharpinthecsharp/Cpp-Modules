#include "Zombie.hpp"

Zombie::Zombie( void ) {
    std::cout << "Zombie Constructor called." << std::endl; 
}

Zombie::~Zombie( void ) {
    std::cout << "Zombie Destructor called." << std::endl; 
}

void Zombie::setName( std::string name ) {
    _name = name;
}

void Zombie::announce( void ) {
    std::cout << "New zombie created named: " << _name << std::endl;
}