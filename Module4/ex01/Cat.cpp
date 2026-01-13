#include "Cat.hpp"

Cat::Cat() : Animal() {
    Animal::_type = "Cat";
}

Cat::~Cat() {

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