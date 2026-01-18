#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _pos(0) {
    for (int i = 0; i < 4; i++)
        this->_materias[i] = NULL;
    std::cout << "MateriaSource constructor called." << std::endl;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (this->_materias[i])
            delete this->_materias[i];
    }
    std::cout << "MateriaSource destructor called." << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& ms ) {
    *this = ms;
}

MateriaSource &MateriaSource::operator=( const MateriaSource& ms ) {
    if (this != &ms) {
        this->_pos = ms._pos;
        for (int i = 0; i < 4; i++) {
            this->_materias[i] = ms._materias[i];
        }
    }
    return (*this);
}

void MateriaSource::learnMateria( AMateria* m ) {
    if (_pos >= 4) {
        std::cout << "Cannot learn more." << std::endl;
        return ;
    }
    _materias[_pos] = m;
    _pos++;
}
AMateria* MateriaSource::createMateria( const std::string& type ) {
    if (type != "cure" && type != "ice") {
        std::cout << "Type don't exist." << std::endl;
        return 0;
    }
    for (int i = 0; i < _pos; i++) {
        if (_materias[i]->getType() == type)
            return _materias[i]->clone();
    }
    std::cout << "Type don't exist." << std::endl;
    return 0;
}