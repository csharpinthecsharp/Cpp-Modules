#include "Brain.hpp"

Brain::Brain() {

}

Brain::~Brain() {
    delete[] _ideas;
}

Brain::Brain( const Brain& bn ) {
    *this = bn;
}

Brain &Brain::operator=( const Brain& bn ) {
    if (this != &bn) {
        for (size_t i = 0; i < BRAIN_SIZE; i++)
            _ideas[i] = bn._ideas[i];
    }
    return *this;
}