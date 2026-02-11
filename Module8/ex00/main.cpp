#include "easyfind.hpp"
#include "easyfind.tpp"

int main() {
    std::vector<int> v_int;
    std::list<int> l_int;

    for (int i(0); i < 10; i++)
        v_int.push_back(i);
    for (int i(0); i < 10; i++)
        l_int.push_back(i);

    try {
        std::vector<int>::iterator ir = easyfind(v_int, 2);
        std::cout << "Occurence found: " << *ir << std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator ir = easyfind(l_int, 12);
        std::cout << "Occurence found:" << *ir <<  std::endl;
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}