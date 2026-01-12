#include "Animal.hpp"

Animal::Animal() : _type("default") {

}

Animal::Animal( const std::string& type ) : _type(type) {
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

void Animal::makeSound() {
    if (_type == "dog")
        std::cout << "Waf!" << std::endl;
    else if (_type == "cat")
        std::cout << "Meow!" << std::endl;
}

const std::string Animal::getType() const {
    return this->_type;
}
