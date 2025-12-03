#include "phonebook.header.hpp"

std::string get_single(std::string name)
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

Contact get_infos()
{
    Contact c("", "", "", "", "");
    c.first_name = get_single("first name");
    c.last_name = get_single("last name");
    c.nickname = get_single("nickname");
    c.phone_number = get_single("phone number");
    c.darkest_secret = get_single("darkest secret");
    return c;
}

int get_num()
{
    std::string res;
    while (!res.length()) {
        std::cout << "Please type the contact you want to reach:\n";
        std::getline(std::cin, res);
        if (!ft_is_singledigit(res)) {
            std::cout << "Warning: expected a single digit." << "\n";
            return -1;
        }
    }
    return std::stoi(res);
}