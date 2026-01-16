#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* al[NB_ANIMALS];
    for (int i = 0; i < NB_ANIMALS; i++) {
        if (i >= NB_ANIMALS/2)
            al[i] = new Cat();
        else
            al[i] = new Dog();
        al[i]->makeSound();
        al[i]->getBrain()->setIdeas("+ de chats");
        al[i]->getBrain()->setIdeas("+ de patées pour les chats");
        al[i]->getBrain()->setIdeas("encore + de chats");
    }

    for (int i = 0; i < NB_ANIMALS; i++) {
        std::cout << "=== Animal[" << i << "] | Type["
         << al[i]->getType() << "] ===" << std::endl;
        for (int j = 0; j < BRAIN_SIZE; j++) {
            if (!al[i]->getBrain()->getIdeas(j).empty())
                std::cout << al[i]->getBrain()->getIdeas(j) << std::endl;
        }
    }

    // DEEP COPY CHECKING BALALALABAAAAA
    Dog* dog = new Dog;
    Cat* cat = new Cat;

    cat->getBrain()->setIdeas("GTA6 en avance");
    cat->getBrain()->setIdeas("100GB de Ram DDR5");
    dog->getBrain()->setIdeas("Un os tout de suite");
    dog->getBrain()->setIdeas("Une balle TOUT DE SUITE");
    
    Dog* dogDeepCopy = new Dog(*dog);
    Cat* catDeepCopy = new Cat(*cat);

    std::cout << "=== Deep copy of the cat ===" << std::endl;
    std::cout << catDeepCopy->getBrain()->getIdeas(0) << std::endl;
    std::cout << catDeepCopy->getBrain()->getIdeas(1) << std::endl; 
    std::cout << "=== Deep copy of the dog ===" << std::endl;  
    std::cout << dogDeepCopy->getBrain()->getIdeas(0) << std::endl;   
    std::cout << dogDeepCopy->getBrain()->getIdeas(1) << std::endl;

    for (int i = 0; i < NB_ANIMALS; i++) {
        delete al[i];
    }

    delete cat;
    delete dog;
    delete catDeepCopy;
    delete dogDeepCopy;
}