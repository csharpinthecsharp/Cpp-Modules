#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string &name ) 
	: _energy(10), _health(10), _damage(0) {
    	std::cout << "ClapTrap constructor called" << std::endl;
		_name = name;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& cp ) 
	: _energy(_energy), _health(_health), _damage(_damage){
		std::cout << "ClapTrap copy constructor called" << std::endl;
		*this = cp;
}

ClapTrap &ClapTrap::operator=( const ClapTrap& cp ) {
	if (this != &cp)
		this->setName(cp.getName());
		this->setEnergy(cp.getEnergy());
		this->setDamage(cp.getDamage());
		this->setHealth(cp.getHealth());
	std::cout << "ClapTrap copy assignement operator called" << std::endl;
	return (*this);
}

void ClapTrap::attack( const std::string& target ) {
	if (getEnergy() > 0 && getHealth() > 0) {
		setEnergy(getEnergy() - 1);
		std::cout << getName() 
			<< " attacks " << target << " causing "
				<< getDamage() << " points of damage! (-1 Energy=[" << getEnergy() << "]) " << std::endl;
		return ;
	}
	std::cout << getName() << " cannot attack!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	int r_amount = getHealth() - amount;
	if (getHealth() == 0) {
		std::cout << "Hitting a dead body is a war crime.." << std::endl;
		return ;
	}
	if (r_amount <= 0) {
		std::cout << getName()
			<< " took a fatal hit and..died :)" << std::endl;
		setHealth(0);
		return ;
	}
	setHealth(getHealth() - amount);
	std::cout << getName() 
		<< " lost " << amount << " HP! " << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (getEnergy() > 0 && getHealth() > 0) {
		setEnergy(getEnergy() - 1);
		setHealth(getHealth() + amount);
		std::cout << getName() 
			<< " restored " << amount << " hp! (-1 Energy=[" << getEnergy() << "]) " << std::endl;
		return ;
	}
	std::cout << getName() << " cannot repair himself!" << std::endl;
}

void ClapTrap::setEnergy( const int& value ) {
	this->_energy = value;
}
void ClapTrap::setDamage( const int& value ) {
	this->_damage = value;
}

void ClapTrap::setHealth( const int& value ) {
	this->_health = value;
}

void ClapTrap::setName( const std::string& value ) {
	this->_name = value;
}

const int ClapTrap::getEnergy() const {
	return this->_energy;
}

const int ClapTrap::getDamage() const {
	return this->_damage;
}

const int ClapTrap::getHealth() const {
	return this->_health;
}

const std::string ClapTrap::getName() const {
	return this->_name;
}

std::ostream& operator<<( std::ostream& os, const ClapTrap& cp ) {
	os << "------ STATS ------" << std::endl;
	os << "Name: " << cp.getName() << std::endl;
	os << "Health: " << cp.getHealth() << std::endl;
	os << "Energy: " << cp.getEnergy() << std::endl;
	os << "Damage: " << cp.getDamage() << std::endl;
	os << "------ ----- ------" << std::endl;
	return os;
}