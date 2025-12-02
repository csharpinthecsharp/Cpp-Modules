#include "phonebook.class.hpp"

void PhoneBook::add(const Contact& c){
    if (nb_contacts == MAX_CONTACT) {
        std::cout << "Max contacts reached, last one was replaced." << "\n";
        contacts[MAX_CONTACT - 1] = c;
    }
    else {
        contacts[nb_contacts] = c;
        nb_contacts+=1;
        std::cout << "New contact added -> " << c.nickname << "\n";
    }        
}