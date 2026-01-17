#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iomanip>
#include <iostream>

#define NB_ANIMALS 4
#include "Brain.hpp"

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        virtual ~Animal();
        Animal( const Animal& al );
        Animal &operator=( const Animal& al );

        virtual void makeSound() const = 0;
        const std::string getType() const;
        virtual Brain *getBrain() const = 0;
        // virtual = 0;  -> abstract class, cannot be instantiate
};

#endif