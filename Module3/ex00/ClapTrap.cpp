#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
}

ClapTrap::~ClapTrap() {
}

ClapTrap::ClapTrap( const ClapTrap& cp ) {
}

ClapTrap ClapTrap::&operator=( const ClapTrap& cp ) {
}

void ClapTrap::attack( const std::string& target ) {

}

void ClapTrap::takeDamage( unsigned int amount ) {
}

void beRepaired( unsigned int amount ) {
	_health += amount;
}
