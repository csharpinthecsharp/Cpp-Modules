#include "phonebook.class.hpp"

std::string prompt_me()
{
    std::string sel;
    std::cout << "Please type:" << "\n";
    std::getline(std::cin, sel);
    if (!sel.length())
        std::cout << "Error" << "\n";
    return (sel);
}

int check_sel(std::string& sel, PhoneBook& phoneb)
{
    std::string str;
    if (sel == "ADD") {
        str = prompt_me();
        if (phoneb.nb_contacts == 8) {

            phoneb.contacts[8] = str;
        }
        else {
            phoneb.contacts[phoneb.nb_contacts] = str;
            phoneb.nb_contacts+=1;
        }
    }
    else if (sel == "SEARCH") {
        str = prompt_me();
        for (int i = 0; i < phoneb.nb_contacts; i++) {
            if (phoneb.contacts[i] == str)
                std::cout << "Found: " << str << "\n"; 
        }
    }
    else if (sel == "EXIT") {
        std::cout << "Exiting.." << "\n";
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    PhoneBook phoneb;
    while (1) {
        std::string sel;
        std::cout << "Please type: ADD, SEARCH or EXIT" << "\n";
        std::getline(std::cin, sel);
        if (!sel.length())
            std::cout << "Error" << "\n";
        if (sel.length()) {
            if (check_sel(sel, phoneb) == 1)
                return (0);
        }
    }
    return (0);
}