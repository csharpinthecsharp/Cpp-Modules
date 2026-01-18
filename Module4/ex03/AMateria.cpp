#include "AMateria.hpp"

AMateria::AMateria( std::string const& type ) : _type(type) {
    std::cout << "AMateria constructor called." << std::endl;

}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called." << std::endl;
}

AMateria::AMateria( const AMateria& aa ) {
    *this = aa;
}

AMateria &AMateria::operator=(const AMateria& aa ) {
    if (this != &aa) {
        this->_type = aa._type;
    }
    return *this;
}

std::string const& AMateria::getType() const {
    return this->_type;
}

void AMateria::use( ICharacter& target ) {

}