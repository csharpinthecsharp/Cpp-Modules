#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice constructor called." << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice destructor called." << std::endl;
}

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
    return new Ice(*this);
}
void Ice::use( ICharacter& target ) {
    std::cout << "* shoot an " << this->getType() <<
     " bolt at " << target.getName() << " *" << std::endl;
}
