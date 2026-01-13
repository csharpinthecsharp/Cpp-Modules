#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* dg = new Dog();
    const Animal* ct = new Cat();
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();
    
    std::cout << "=== Virtual makeSound() in base class ===" << std::endl;
    std::cout << meta->getType() << std::endl;
    std::cout << dg->getType() << std::endl;
    std::cout << ct->getType() << std::endl;
    
    meta->makeSound();
    dg->makeSound();
    ct->makeSound();

    std::cout << "=== No virtual makeSound() in base class ===" << std::endl;
    std::cout << wa->getType() << std::endl;
    std::cout << wc->getType() << std::endl;

    wa->makeSound();
    wc->makeSound();

    delete meta;
    delete dg;
    delete ct;
    delete wa;
    delete wc;

    return 0;
}