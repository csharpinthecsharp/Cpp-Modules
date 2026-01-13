#include "Animal.hpp"

Animal::Animal() : _type("Animal") {

}

Animal::~Animal() {

}

Animal::Animal( const Animal& al ) {
    *this = al;
}
Animal &Animal::operator=( const Animal& al ) {
    if (this != &al) {
        this->_type = al._type;
    }
    return *this;
}

void Animal::makeSound() const {
    std::cout << "Animal talking!" << std::endl;
}
const std::string Animal::getType() const {
    return this->_type;
}
