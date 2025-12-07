#include "iostream"
#include "iomanip"

int main( int ac, char **av ) {
    std::string stringBRAIN = "HI THIS IS BRAIN";
    std::string* stringPTR = &stringBRAIN; // Pointer store the adress of the var.
    std::string& stringREF = stringBRAIN; // Reference is a alias of the var.

    std::cout << "         ---- Mem Address ----" << std::endl;
    std::cout << "The memory address of the string variable: " << &stringBRAIN << std::endl;
    std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << "\n            ---- Value ----" << std::endl;
    std::cout << "The value of the string variable: " << stringBRAIN << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;

    std::cout << "\n            ---- Bonus ----" << std::endl;
    std::cout << "The mem adress of (and not held) stringPTR: " << &stringPTR << std::endl;
}