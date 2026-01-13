#ifndef BRAIN_HPP
#define BRAIN_HPP
#define BRAIN_SIZE 100

#include <iostream>

class Brain {
    private:
        std::string _ideas[BRAIN_SIZE];
    public:
        Brain();
        ~Brain();
        Brain( const Brain& bn );
        Brain &operator=( const Brain& bn );
};

#endif