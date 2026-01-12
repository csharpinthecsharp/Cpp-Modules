#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iomanip>
#include <iostream>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal( const std::string& type );
        ~Animal();
        Animal( const Animal& al );
        Animal &operator=( const Animal& al );

        void makeSound();
        const std::string getType() const;
};

#endif