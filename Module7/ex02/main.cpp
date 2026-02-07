#include "Array.hpp"

#define SIZE_IN_BOUNDS 10
#define SIZE_OUT_OF_BOUNDS 1

int main() {
    Array<unsigned int> iArray(SIZE_IN_BOUNDS);
    Array<std::string> sArray(SIZE_IN_BOUNDS);
    Array<float> fArray(SIZE_IN_BOUNDS);
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