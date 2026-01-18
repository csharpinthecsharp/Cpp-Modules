#include "Ice.hpp"

Ice::Ice() : _type("ice"), AMateria(_type) { }

Ice::~Ice() { }

Ice::Ice( const Ice& ie ) : AMateria(ie) {
    *this = ie;
}

Ice &Ice::operator=( const Ice& ie ) {
    if (this != &ie) {
        this->_type = ie._type;
    }
    return *this;
}

AMateria* Ice::clone() const {
    
}
void Ice::use( ICharacter& target ) {
    std::cout << "* shoot an " << this->getType() <<
     " bolt at " << target.getName() << " *" << std::endl;
}
