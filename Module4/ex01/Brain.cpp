#include "Brain.hpp"

Brain::Brain() : _pos(0) {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain( const Brain& bn ) {
    *this = bn;
    std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=( const Brain& bn ) {
    if (this != &bn) {
        for (size_t i = 0; i < BRAIN_SIZE; i++)
            _ideas[i] = bn._ideas[i];
    }
    std::cout << "Brain copy asignment operator called" << std::endl;
    return *this;
}

const std::string &Brain::getIdeas( size_t index ) const {
    return this->_ideas[index];
}

void Brain::setIdeas( std::string ideas ) {
    if (_pos == BRAIN_SIZE) {
        std::cout << "Ideas size is " << BRAIN_SIZE <<
         ", you cannot add more." << std::endl;
        return ;
    }
    _ideas[_pos++] = ideas;
}
