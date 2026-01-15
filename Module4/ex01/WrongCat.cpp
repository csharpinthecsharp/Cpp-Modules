#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    WrongAnimal::_type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& ct ) {
    *this = ct;
    std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=( const WrongCat& ct ) {
    if (this != &ct) {
        this->_type = ct._type;
    }
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongMeeooow!" << std::endl;
}