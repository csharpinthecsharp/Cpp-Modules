#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* dg = new Dog();
    const Animal* ct = new Cat();
    
    std::cout << meta->getType() << std::endl;
    std::cout << dg->getType() << std::endl;
    std::cout << ct->getType() << std::endl;

    meta->makeSound();
    dg->makeSound();
    ct->makeSound();

    delete meta;
    delete dg;
    delete ct;

    return 0;
}