#include "FragTrap.hpp"

FragTrap::FragTrap( const std::string name ) : ClapTrap(name) {
    std::cout << "FragTrap constructor called" << std::endl;
    this->_name = name;
    this->_health = 100;
    this->_energy = 100;
    this->_damage = 30;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap( const FragTrap& ft ) : ClapTrap(ft) {
    *this = ft;
}
FragTrap &FragTrap::operator=( const FragTrap& ft ) {
    if (this != &ft) {
        this->setName(ft.getName());
        this->setHealth(ft.getHealth());
        this->setEnergy(ft.getEnergy());
        this->setDamage(ft.getDamage());
    }
    return *this;
}

void FragTrap::highFivesGuys( void ) {
    std::cout << "Hey!! Would you like to high fives guys ??? :)" << std::endl;
}