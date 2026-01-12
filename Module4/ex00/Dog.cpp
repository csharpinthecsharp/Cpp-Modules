#include "Dog.hpp"

Dog::Dog() : Animal("dog") {
}

Dog::~Dog() {

}

Dog::Dog( const Dog& dg ) {
    *this = dg;
}

Dog &Dog::operator=( const Dog& dg ) {
    if (this != &dg) {
        this->_type = dg._type;
    }
    return *this;
}