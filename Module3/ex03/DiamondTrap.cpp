#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( const std::string& name ) : ClapTrap(name),
                                                    ScavTrap(name), FragTrap(name),
                                                    name(name) {
    ClapTrap::setName(name + "_clap_name");
    this->setEnergy(50);
    this->setHealth(100);
    this->setDamage(30);
    std::cout << CYAN BOLD << "[DiamondTrap]: " << RESET << "constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << CYAN BOLD << "[DiamondTrap]: " << RESET << "destructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& dt ) : ClapTrap(dt), FragTrap(dt), ScavTrap(dt) {
    *this = dt;
    std::cout << CYAN BOLD << "[DiamondTrap]: " << RESET << "copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=( const DiamondTrap& dt ) {
    if (this != &dt) {
        this->name = dt.getName();  
        this->setDamage(dt.getDamage());
        this->setEnergy(dt.getEnergy());
        this->setHealth(dt.getHealth());
    }
    std::cout << CYAN BOLD << "[DiamondTrap]: " << RESET << "copy assignement operator called" << std::endl;
    return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << CYAN BOLD << "[DiamondTrap]: " << RESET << "Im am.. " << name << std::endl;
    std::cout << CYAN BOLD << "[DiamondTrap]: " << RESET << "My ClapTrap name is.. " << ClapTrap::getName() << std::endl;
}