#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( const std::string& name ) : name(name),
                                                    ClapTrap(name + "_clap_name"),
                                                    FragTrap(name),
                                                    ScavTrap(name) {
    std::cout << "DiamondTrap constructor called" << std::endl;
    this->setEnergy(ScavTrap::getEnergy());
    this->setHealth(FragTrap::getHealth());
    this->setDamage(FragTrap::getDamage());
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& dt ) : ClapTrap(dt), FragTrap(dt), ScavTrap(dt) {
    *this = dt;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap& dt ) {
    if (this != &dt) {
        this->setName(dt.getName());
        this->setDamage(dt.getDamage());
        this->setEnergy(dt.getEnergy());
        this->setHealth(dt.getHealth());
    }
    return *this;
}

void DiamondTrap::whoAmI() {

}