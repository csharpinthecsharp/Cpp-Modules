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

        const std::string& getIdeas( size_t index ) const;
        void setIdeas( std::string& ideas );
};

#endif