#include "Dog.hpp"

Dog::Dog() : Animal() {
    Animal::_type = "Dog";
    this->_br = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
    delete this->_br;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog( const Dog& dg ) {
    *this = dg;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=( const Dog& dg ) {
    if (this != &dg) {
        this->_type = dg._type;
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Waaaafff!" << std::endl;
}

Brain *Dog::getBrain() const {
    return this->_br;
}