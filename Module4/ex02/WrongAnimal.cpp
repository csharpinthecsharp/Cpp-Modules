#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& al ) {
    *this = al;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal &WrongAnimal::operator=( const WrongAnimal& al ) {
    if (this != &al) {
        this->_type = al._type;
    }
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal talking!" << std::endl;
}
const std::string WrongAnimal::getType() const {
    return this->_type;
}
