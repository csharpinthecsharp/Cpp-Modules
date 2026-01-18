#include "Character.hpp"

Character::Character() : _name("default"), _pos(0) {

}

Character::~Character() {
 
}

Character::Character( const std::string& name ) : _name(name) {

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
    if (_pos >= 4 || _pos < 0) {
        std::cout << "Inventory is full." << std::endl;
        return ;
    }
    _inventory[_pos] = m;
    _pos++;
}

void Character::unequip( int idx ) {
    if (idx >= 4 || idx < 0) 
        return ;
    _inventory[_pos] = NULL;
}

void Character::use( int idx, ICharacter& target ) {
    _inventory[idx]->use(target);
}