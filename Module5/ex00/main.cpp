#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat a(1, "Johé");
        std::cout << a << std::endl;
        a.incrementGrade();
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }

    try {    
        Bureaucrat b(100, "Ya");
        std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch ( std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Bureaucrat c(151, "Jack");
    }
    catch ( std::exception & e ) {
        std::cout << e.what() << std::endl;
    }
}