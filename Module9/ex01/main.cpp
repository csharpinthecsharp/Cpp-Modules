#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    RPN rp;
    rp.addElements(av[1]);
    std::cout << rp << std::endl;
}
