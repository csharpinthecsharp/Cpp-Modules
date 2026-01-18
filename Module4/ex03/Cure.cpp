#include "Cure.hpp"

Cure::Cure() : _type("cure"), AMateria(_type) {

}

Cure::~Cure() {

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

}

void Cure::use( ICharacter& target ) {
    std::cout << "* heals " << target.getName() <<
     "'s wounds *" << std::endl;
}