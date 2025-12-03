#include "phonebook.header.hpp"

std::string transform_string(std::string string)
{
    std::string res = string;
    int len = res.length();
    int max_len = 10;
    if (len <= max_len)
    {
        if ((max_len - len) == 0)
            return string;
        else
        {
            for (int i = 0; i < (max_len - len); i++)
                res.append(" ");
        }
    }
    else
    {
        for (int i = 0; len >= max_len; i++) { 
            res.pop_back();
            len--;
        }
        res.append(".");
    }
    return res;
}

int check_sel(std::string& sel, PhoneBook& phoneb)
{
    Contact c("", "", "", "", "");
    int num = -1;
    if (sel == "ADD") {
        c = get_infos();
        phoneb.add(c);
    }
    else if (sel == "SEARCH") {

        std::cout << "Index     " << "|";
        std::cout << "First Name" << "|";
        std::cout << "Last Name " << "|";
        std::cout << "Nickname  " << "\n";

        for (int i = 0; i < phoneb.nb_contacts; i++) {
            std::cout << i + 1 << "         " << "|"; 
            std::cout << transform_string(phoneb.contacts[i].first_name) << "|";
            std::cout << transform_string(phoneb.contacts[i].last_name) << "|";
            std::cout << transform_string(phoneb.contacts[i].nickname) << "\n";
        }
        while (num < 1 || num > 8)
            num = get_num();
        if (!phoneb.contacts[num - 1].first_name.empty()) {
            std::cout << phoneb.contacts[num - 1].first_name << "\n";
            std::cout << phoneb.contacts[num - 1].last_name << "\n";
            std::cout << phoneb.contacts[num - 1].nickname << "\n";
            std::cout << phoneb.contacts[num - 1].phone_number << "\n";
            std::cout << phoneb.contacts[num - 1].darkest_secret << "\n";
        }
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