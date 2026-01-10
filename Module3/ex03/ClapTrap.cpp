#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string &name ) 
	: _name(name), _energy(10), _health(10), _damage(0) {
    	std::cout << MAGENTA BOLD << "[ClapTrap]: " << RESET << "constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << MAGENTA BOLD << "[ClapTrap]: " << RESET <<
	 "destructor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& cp ) {
		std::cout << MAGENTA BOLD <<"[ClapTrap]: " << RESET<<
		 "copy constructor called" << std::endl;
		*this = cp;
}

ClapTrap &ClapTrap::operator=( const ClapTrap& cp ) {
	if (this != &cp) {
		this->setName(cp.getName());
		this->setEnergy(cp.getEnergy());
		this->setDamage(cp.getDamage());
		this->setHealth(cp.getHealth());
	}
	std::cout << MAGENTA BOLD << "[ClapTrap]: " << RESET <<
	 "copy assignment operator called" << std::endl;
	return (*this);
}

void ClapTrap::attack( const std::string& target ) {
	if (getEnergy() > 0 && getHealth() > 0) {
		setEnergy(getEnergy() - 1);
		std::cout << MAGENTA BOLD << "[ClapTrap]: " << RESET << getName() << " attacks " << target << " causing "
				<< getDamage() << " points of damage! (-1 Energy=[" << getEnergy() << "]) " << std::endl;
		return ;
	}
	std::cout << MAGENTA BOLD << "[ClapTrap]: " << RESET << getName() << " cannot attack, he's dead!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	int r_amount = getHealth() - amount;
	if (getHealth() == 0) {
		std::cout << MAGENTA BOLD << "[ClapTrap]: " << RESET << getName() << " is already dead!" << std::endl;
		return ;
	}
	if (r_amount <= 0) {
		std::cout << MAGENTA BOLD << "[ClapTrap]: " << RESET << getName()
			<< " took a fatal hit and..died.." << std::endl;
		setHealth(0);
		return ;
	}
	setHealth(getHealth() - amount);
	std::cout << MAGENTA BOLD << "[ClapTrap]: " << RESET << getName() 
		<< " took a hit! " << "(-" << amount << ") Health=[" << getHealth() << "]) " << std::endl;
	return ;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (getEnergy() > 0 && getHealth() > 0) {
		setEnergy(getEnergy() - 1);
		setHealth(getHealth() + amount);
		std::cout << MAGENTA BOLD "[ClapTrap]: " << RESET << getName() 
			<< " restored " << amount << " hp! (-1 Energy=[" << getEnergy() << "]) " << std::endl;
		return ;
	}
	std::cout << MAGENTA BOLD "[ClapTrap]: " << RESET << getName() << " cannot repair himself, he's dead!" << std::endl;
}

void ClapTrap::setEnergy( unsigned int value ) {
	this->_energy = value;
}
void ClapTrap::setDamage( unsigned int value ) {
	this->_damage = value;
}

void ClapTrap::setHealth( unsigned int value ) {
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
	os << YELLOW BOLD << "------ STATS ------" << RESET << std::endl;
	os << GREEN << "Name: " << CYAN << cp.getName() << RESET << std::endl;
	os << GREEN << "Health: " << CYAN <<cp.getHealth() << RESET<< std::endl;
	os << GREEN << "Energy: " << CYAN << cp.getEnergy() << RESET << std::endl;
	os << GREEN << "Damage: " << CYAN << cp.getDamage() << RESET<< std::endl;
	os << YELLOW BOLD "------ ----- ------" << RESET << std::endl;
	return os;
}