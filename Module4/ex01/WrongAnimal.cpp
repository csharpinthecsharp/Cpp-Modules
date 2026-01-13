#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {

}

WrongAnimal::~WrongAnimal() {

}

WrongAnimal::WrongAnimal( const WrongAnimal& al ) {
    *this = al;
}
WrongAnimal &WrongAnimal::operator=( const WrongAnimal& al ) {
    if (this != &al) {
        this->_type = al._type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal talking!" << std::endl;
}
const std::string WrongAnimal::getType() const {
    return this->_type;
}
