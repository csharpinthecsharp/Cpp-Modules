#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    private:
        bool _guard;
    public:
        ScavTrap( const std::string& name );
        ScavTrap( const ScavTrap& st );
        ScavTrap &operator=( const ScavTrap& st );
        ~ScavTrap();

        void attack( const std::string& target );
        void guardGuate();
};

#endif