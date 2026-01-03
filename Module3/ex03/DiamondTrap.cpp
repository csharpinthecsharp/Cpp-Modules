#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( const std::string& name ) : ClapTrap(name),
                                                    ScavTrap(name), FragTrap(name),
                                                    name(name) {
    std::cout << "DiamondTrap constructor called" << std::endl;
    ClapTrap::setName(name + "clap_name");
    this->setEnergy(ScavTrap::getEnergy());
    this->setHealth(FragTrap::getHealth());
    this->setDamage(FragTrap::getDamage());
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& dt ) : ClapTrap(dt), FragTrap(dt), ScavTrap(dt) {
    std::cout << "Copy constructor called" << std::endl;
    *this = dt;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap& dt ) {
    if (this != &dt) {
        this->name = dt.getName();  
        this->setDamage(dt.getDamage());
        this->setEnergy(dt.getEnergy());
        this->setHealth(dt.getHealth());
    }
    std::cout << "Copy assignement operator called" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "Im am.. " << name << std::endl;
    std::cout << "My ClapTrap name is.. " << ClapTrap::getName() << std::endl;
}