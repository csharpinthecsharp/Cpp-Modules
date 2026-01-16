#include "Cat.hpp"

Cat::Cat() : Animal() {
    Animal::_type = "Cat";
    _br = new Brain();
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
    delete _br;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat( const Cat& ct ) {
    *this = ct;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=( const Cat& ct ) {
    if (this != &ct) {
        this->_type = ct._type;
        this->_br = new Brain(*ct._br);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meeooow!" << std::endl;
}

Brain *Cat::getBrain() const {
    return this->_br;
}
