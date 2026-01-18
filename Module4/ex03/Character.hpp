#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Character : public ICharacter {
    private:
        std::string _name;
        AMateria* _inventory[4];
        size_t _pos;
    public:
        Character();
        ~Character();
        Character( const std::string& name );
        Character( const Character& cr );
        Character &operator=( const Character& cr );

        std::string const& getName() const;
        void equip( AMateria* m );
        void unequip( int idx );
        void use( int idx, ICharacter& target );
};

#endif