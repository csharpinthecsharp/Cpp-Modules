#include "Cat.hpp"

Cat::Cat() : Animal() {
    Animal::_type = "Cat";
    _br = new Brain();
}

Cat::~Cat() {
    delete _br;
}

Cat::Cat( const Cat& ct ) {
    *this = ct;
}

void Cat::makeSound() const {
    std::cout << "Meeooow!" << std::endl;
}

Cat &Cat::operator=( const Cat& ct ) {
    if (this != &ct) {
        this->_type = ct._type;
    }
    return *this;
}