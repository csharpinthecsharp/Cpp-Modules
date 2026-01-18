#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria* _materias[4];
        size_t _pos;
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource( const MateriaSource& ms );
        MateriaSource &operator=( const MateriaSource& ms );

        void learnMateria( AMateria* m);
        AMateria* createMateria( std::string const& type );
};

#endif