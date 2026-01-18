#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria {
    protected:
        std::string _type;
    public:
        AMateria( std::string const& type );
        virtual ~AMateria();
        AMateria( const AMateria& aa );
        AMateria &operator=(const AMateria& aa );

        std::string const& getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use( ICharacter& target );
};

#endif 