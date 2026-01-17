#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iomanip>
#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal( const WrongAnimal& al );
        WrongAnimal &operator=( const WrongAnimal& al );

        void makeSound() const;
        const std::string getType() const;
};

#endif