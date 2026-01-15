#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain* _br;
    public:
        Dog();
        ~Dog();
        Dog( const Dog& dg );
        Dog &operator=( const Dog& dg );

        void makeSound() const;
        Brain* getBrain() const;
};

#endif