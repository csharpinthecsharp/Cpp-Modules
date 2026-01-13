#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    WrongAnimal::_type = "WrongCat";
}

WrongCat::~WrongCat() {

}

WrongCat::WrongCat( const WrongCat& ct ) {
    *this = ct;
}

void WrongCat::makeSound() const {
    std::cout << "WrongMeeooow!" << std::endl;
}

WrongCat &WrongCat::operator=( const WrongCat& ct ) {
    if (this != &ct) {
        this->_type = ct._type;
    }
    return *this;
}