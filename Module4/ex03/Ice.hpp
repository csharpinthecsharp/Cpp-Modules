#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
    private:
        std::string _type;
    public:
        Ice();
        ~Ice();
        Ice( const Ice& ie );
        Ice &operator=( const Ice& ie );

        AMateria* clone() const;
        void use( ICharacter& target );
};

#endif