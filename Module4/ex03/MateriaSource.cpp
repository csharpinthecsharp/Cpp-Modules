#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _pos(0) {

}

MateriaSource::~MateriaSource() {

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

void MateriaSource::learnMateria( AMateria* aa ) {
    if (_pos >= 4 || _pos < 0) {
        std::cout << "Materias is full" << std::endl;
        return ;
    }
    _materias[_pos] = aa;
    _pos++;
}
AMateria* MateriaSource::createMateria( std::string const& type ) {
    if (type != "cure" || type != "ice")
        return 0;
    if (_pos - 1 < 0)
        return 0;
    return _materias[_pos - 1];
}