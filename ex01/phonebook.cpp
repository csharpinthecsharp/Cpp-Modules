#include "phonebook.header.hpp"

int check_sel(std::string& sel, PhoneBook& phoneb)
{
    Contact c;
    int num = -1;
    if (sel == "ADD") {
        c = c.getter();
        phoneb.add(c);
    }
    else if (sel == "SEARCH")
        phoneb.search();
    else if (sel == "EXIT") {
        std::cout << "Exiting." << "\n";
        return (1);
    }
    return 0;
}

int main(int ac, char **av)
{
    PhoneBook phoneb;
    while (1) {
        std::string sel;
        std::cout << "[PhoneBook] - Commands: ADD, SEARCH or EXIT" << "\n";
        std::getline(std::cin, sel);
        if (sel.length()) {
            if (check_sel(sel, phoneb) == 1)
                return (0);
        }
    }
    return 0;
}
