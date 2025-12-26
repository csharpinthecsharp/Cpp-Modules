#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap( const std::string name );
        ~FragTrap();
        FragTrap( const FragTrap& ft );
        FragTrap &operator=( const FragTrap& ft );

        void highFivesGuys( void );
};

#endif