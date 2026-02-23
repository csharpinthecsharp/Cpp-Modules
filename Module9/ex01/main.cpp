#include "RPN.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    try {
        RPN rp(av[1]);
        std::cout << rp << std::endl;
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    } 
}
