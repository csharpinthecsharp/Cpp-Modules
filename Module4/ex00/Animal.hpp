#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iomanip>
#include <iostream>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        ~Animal();
        Animal( const Animal& al );
        Animal &operator=( const Animal& al );

        virtual void makeSound() const;
        const std::string getType() const;
};

#endif