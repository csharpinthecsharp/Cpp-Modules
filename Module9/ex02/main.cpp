#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
    if (ac < 3) {
        std::cout << "Error: Min 2 numbers" << std::endl;
        return (1);
    }

    PmergeMe pm;
    PmergeMe::Pair p = pm.getPair();

    for (int i(1); i < ac -1; i+=2) {
        int a = atoi(av[i]);
        int b = atoi(av[i + 1]);
        if (a <= 0 || b <= 0)
            throw "Error: Arguments list contains a non positive integer";
        if (a < b) {
            p.a = b;
            p.b = a;
        }
        else {
            p.a = a;
            p.b = b;
        }
        pm.getVector().push_back(p);
        pm.getDeque().push_back(p);
    }
}