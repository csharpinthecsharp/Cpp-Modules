#include "Character.hpp"

Character::Character() : _name("default"), _pos(0) {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL;
    std::cout << "Character default constructor called." << std::endl; 
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
    std::cout << "Character destructor called." << std::endl;
}

Character::Character( const std::string& name ) : _name(name), _pos(0) {
    for (int i = 0; i < 4; i++)
        this->_inventory[i] = NULL; 
    std::cout << "Character parameters constructor called." << std::endl; 
}

Character::Character( const Character& cr ) {
    *this = cr;
}
Character &Character::operator=( const Character& cr ) {
    if (this != &cr) {
        this->_name = cr._name;
        this->_pos = cr._pos;
        for (int i = 0; i < 4; i++) {
            this->_inventory[i] = cr._inventory[i];
        }
    }
    return *this;
}

std::string const& Character::getName() const {
    return this->_name;
}

void Character::equip( AMateria* m ) {
    if (_pos >= 4 || _pos < 0 || !m) {
        std::cout << "Unable to equip." << std::endl;
        return ;
    }
    this->_inventory[_pos] = m;
    _pos++;
}

void Character::unequip( int idx ) {
    if (idx >= 4 || idx < 0) 
        return ;
    this->_inventory[idx] = NULL;
}

void Character::use( int idx, ICharacter& target ) {
    if (idx < 0 || idx >= 4 || !this->_inventory[idx]) {
        std::cout << "Unable to use." << std::endl;
        return;
    }
    this->_inventory[idx]->use(target);
}