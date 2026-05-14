#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac < 3) {
        std::cout << "Error: Min 2 numbers" << std::endl;
        return (1);
    }

    PmergeMe pm;
    PmergeMe::Pair p;

    for (int i(1); i < ac -1; i+=2) {
        int a = atoi(av[i]);
        int b = atoi(av[i + 1]);
        try {
            if (a <= 0 || b <= 0)
                throw std::invalid_argument("Arguments list contains a non positive integer");
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        if (a < b) {
            p.a = a;
            p.b = b;
        }
        else {
            p.a = b;
            p.b = a;
        }
        pm.getVector().push_back(p);
        pm.getDeque().push_back(p);
    }
    pm.mergingVector(0, pm.getVector().size());
    pm.buildChain();
    pm.InsertionVector();
    std::cout << pm;
}