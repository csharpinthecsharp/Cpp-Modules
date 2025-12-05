#include "phonebook.header.hpp"

void PhoneBook::add( const Contact& c )
{
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

void PhoneBook::search( void )
{
    int num = -1;
    std::cout << "     Index" << "|";
    std::cout << "First Name" << "|";
    std::cout << "Last Name " << "|";
    std::cout << "  Nickname" << "\n";

    for (int i = 0; i < nb_contacts; i++) {
        std::cout << "         " << i + 1 << "|"; 
        std::cout << std::setw(10) << contacts->formater(contacts[i].first_name); 
        std::cout << "|";
        std::cout << std::setw(10) << contacts->formater(contacts[i].last_name);
        std::cout << "|";
        std::cout << std::setw(10) << contacts->formater(contacts[i].nickname);
        std::cout << "\n";
    }
    while (num < 1 || num > 8)
        num = get_num();
    if (!contacts[num - 1].first_name.empty()) {
        std::cout << contacts[num - 1].first_name << "\n";
        std::cout << contacts[num - 1].last_name << "\n";
        std::cout << contacts[num - 1].nickname << "\n";
        std::cout << contacts[num - 1].phone_number << "\n";
        std::cout << contacts[num - 1].darkest_secret << "\n";
    }
}

