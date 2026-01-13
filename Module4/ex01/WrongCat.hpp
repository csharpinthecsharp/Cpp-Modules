#ifndef WRONGCAT_HPP
#define WRONGAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        ~WrongCat();
        WrongCat( const WrongCat& ct );
        WrongCat &operator=( const WrongCat& ct );

        void makeSound() const;
};

#endif