#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac != 2) {
        std::cout << "Error: Min 2 numbers" << std::endl;
        return (1);
    }

    PmergeMe pm;

    for (int i(0); i < ac; i++) {
        int v = atoi(av[i]);
        if (v <= 0)
            throw "Error: Arguments list contains a non positive integer";
        pm.getVector().push_back(atoi(av[i]));
        pm.getDeque().push_back(atoi(av[i]));
    }
}