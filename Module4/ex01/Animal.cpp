#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal( const Animal& al ) {
    *this = al;
    std::cout << "Animal copy constructor called" << std::endl;
}
Animal &Animal::operator=( const Animal& al ) {
    if (this != &al) {
        this->_type = al._type;
    }
    std::cout << "Animal copy assignement operator called" << std::endl;
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal talking!" << std::endl;
}

const std::string Animal::getType() const {
    return this->_type;
}

