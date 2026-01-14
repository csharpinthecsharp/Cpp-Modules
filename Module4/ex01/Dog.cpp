#include "Dog.hpp"

Dog::Dog() : Animal() {
    Animal::_type = "Dog";
    this->_br = new Brain();
}

Dog::~Dog() {
    delete this->_br;
}

Dog::Dog( const Dog& dg ) {
    *this = dg;
}

void Dog::makeSound() const {
    std::cout << "Waaaafff!" << std::endl;
}

Dog &Dog::operator=( const Dog& dg ) {
    if (this != &dg) {
        this->_type = dg._type;
    }
    return *this;
}