#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* al[10];
    for (int i = 0; i < 10; i++) {
        if (i >= 5)
            al[i] = new Cat();
        else
            al[i] = new Dog();
    }

    for (int i = 0; i < 10; i++) {
        delete al[i];
    }
}