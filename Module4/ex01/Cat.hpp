#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain* _br;
    public:
        Cat();
        ~Cat();
        Cat( const Cat& ct );
        Cat &operator=( const Cat& ct );

        void makeSound() const;
};

#endif