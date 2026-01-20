#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b(0, "Jack");
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }
}