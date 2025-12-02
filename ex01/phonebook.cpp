#include "phonebook.header.hpp"

int check_sel(std::string& sel, PhoneBook& phoneb)
{
    Contact c("", "", "", "", "");
    int num = 0;
    if (sel == "ADD") {
        c = get_infos();
        phoneb.add(c);
    }
    else if (sel == "SEARCH") {

        std::cout << "Index     ";
        std::cout << " | ";
        std::cout << "First Name";
        std::cout << " | ";
        std::cout << "Last Name ";
        std::cout << " | ";
        std::cout << "Nickname  " << "\n";

        num = get_num();
        std::cout << phoneb.contacts[num].first_name << "\n";
        std::cout << phoneb.contacts[num].last_name << "\n";
        std::cout << phoneb.contacts[num].nickname << "\n";
        std::cout << phoneb.contacts[num].phone_number << "\n";
        std::cout << phoneb.contacts[num].darkest_secret << "\n";
    }
    else if (sel == "EXIT") {
        std::cout << "Exiting." << "\n";
        return (1);
    }
    return 0;
}

int main(int ac, char **av)
{
    PhoneBook phoneb;
    Contact contacts;
    while (1) {
        std::string sel;
        std::cout << "Please type: ADD, SEARCH or EXIT" << "\n";
        std::getline(std::cin, sel);
        if (sel.length()) {
            if (check_sel(sel, phoneb) == 1) {
                return (0);
            }
        }
    }
    return 0;
}