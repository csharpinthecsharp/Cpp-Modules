#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
    private:
        std::string name;
    public:
        DiamondTrap( const std::string& name);
        ~DiamondTrap();
        DiamondTrap( const DiamondTrap& dt );
        DiamondTrap &operator=( const DiamondTrap& dt );

        void whoAmI();
};

#endif
