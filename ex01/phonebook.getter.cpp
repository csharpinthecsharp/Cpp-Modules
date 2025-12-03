#include "phonebook.header.hpp"

std::string get_single(std::string& name)
{
    std::string res;
    while (!res.length()) {
        std::cout << "Please type the " << name << " :\n";
        std::getline(std::cin, res);
        if (!res.length()) {
            std::cout << "Warning: empty field is not authorized." << "\n";
        }
    }
    return res;
}

int get_num()
{
    std::string res;
    while (!res.length()) {
        std::cout << "Please type the contact you want to reach:\n";
        std::getline(std::cin, res);
        if (res.length() != 1 || !isdigit(res[0])) {
            std::cout << "Warning: expected a single digit." << "\n";
            return -1;
        }
    }
    return std::stoi(res);
}
