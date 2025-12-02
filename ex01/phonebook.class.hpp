#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#include <iostream>
#include <string>

#define MAX_CONTACT 8
class Contact
{
    public:
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        Contact(std::string l_n, std::string nn, std::string pn, std::string ds) {
            last_name = l_n;
            nickname = nn;
            phone_number = pn;
            darkest_secret = ds;
        }
};

class PhoneBook
{
    public:
        int nb_contacts;
        Contact contacts[8];

        void add(const Contact& c);
};

#endif