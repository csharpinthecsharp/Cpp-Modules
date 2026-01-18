#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure constructor called." << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure destructor called." << std::endl;
}

Cure::Cure( const Cure& ce ) : AMateria(ce) {
    *this = ce;
}

Cure &Cure::operator=( const Cure& ce ) {
    if (this != &ce) {
        this->_type = ce._type;        
    }
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use( ICharacter& target ) {
    std::cout << "* heals " << target.getName() <<
     "'s wounds *" << std::endl;
}