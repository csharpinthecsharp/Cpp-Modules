#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon )
    : _name(name), _weapon(weapon) {} // reference (Weapon& weapon) 
                                      // needs to be initialised at
                                      // the moment the containing obj
                                      // is constructed.
                                      // so it cannot be init inside {}.

HumanA::~HumanA( void ) {
}

void HumanA::attack( void ) {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}