#include "ScavTrap.hpp"

ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name) {
    std::cout << "ScavTrap constructor called" << std::endl;
    this->_name = name;
    this->_energy = 50;
    this->_health = 100;
    this->_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& st ) : ClapTrap(st) {
    *this = st;
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap& st ) {
    if (this != &st) {
        this->setName(st.getName());
        this->setEnergy(st.getEnergy());
        this->setHealth(st.getHealth());
        this->setDamage(st.getDamage());
    }
	std::cout << "ScavTrap copy assignement operator called" << std::endl;
    return *this;
}

void ScavTrap::guardGuate() {
    if (!_guard) {
        _guard = true;
        std::cout << "ScavTrap is now in gate keeper mode" << std::endl;
        return ;
    }
    std::cout << "ScavTrap is already in gate keeper mode" << std::endl;
    return ;
}


ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}


void ScavTrap::attack( const std::string& target ) {
	if (getEnergy() > 0 && getHealth() > 0) {
		setEnergy(getEnergy() - 1);
		std::cout << getName() 
			<< " attacks " << target << " causing "
				<< getDamage() << " points of damage! (-1 Energy=[" << getEnergy() << "]) " << std::endl;
		return ;
	}
	std::cout << getName() << " cannot attack!" << std::endl;
}
