#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define NB_ANIMALS 4

int main() {
    const Animal* al[NB_ANIMALS];
    for (int i = 0; i < NB_ANIMALS; i++) {
        if (i > 1)
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
    
    for (int i = 0; i < 4; i++) {
        delete al[i];
    }
}