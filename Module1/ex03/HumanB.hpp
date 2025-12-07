#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <iomanip>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon* _weapon; // I use a pointer,
                         // because the weapon is not
                         // not passed in the constructor.
    public:
        HumanB( std::string name );
        ~HumanB( void );

        void setWeapon( Weapon& weapon );
        void attack( void );
    };

#endif