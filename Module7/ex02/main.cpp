#include "Array.hpp"

#define SIZE 10

int main() {
    Array<unsigned int> iArray(SIZE);
    Array<std::string> sArray(SIZE);
    Array<float> fArray(SIZE);
    try {
        sArray.setArrayAtIndex("salut", 5);
        fArray.setArrayAtIndex(480.23f, 3);
        iArray.setArrayAtIndex(42, 7);
        std::cout << iArray << std::endl;
        std::cout << sArray << std::endl;
        std::cout << fArray << std::endl;
        std::cout << "size of iArray: " << iArray.size() << std::endl;
        std::cout << "size of sArray: " << sArray.size() << std::endl;
        std::cout << "size of fArray: " << fArray.size() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}