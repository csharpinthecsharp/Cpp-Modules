#include "Phonebook.hpp"

std::string PhoneBook::getFirstName( int index ) {
    return (contacts[index].getFirstName());
}

std::string PhoneBook::getLastName( int index ) {
    return (contacts[index].getLastName());
}

std::string PhoneBook::getNickName( int index ) {
    return (contacts[index].getNickName());
}

std::string PhoneBook::getPhoneNumber( int index ) {
    return (contacts[index].getPhoneNumber());
}

std::string PhoneBook::getDarkestSecret( int index ) {
    return (contacts[index].getDarkestSecret());
}

void PhoneBook::add( void )
{
    Contact c = Contact();
    c.create();

    if (_nb_contacts == MAX_CONTACT) {
        std::cout << "Max contacts reached, last one was replaced." << std::endl;
        contacts[MAX_CONTACT - 1] = c;
    }
    else {
        contacts[_nb_contacts] = c;
        _nb_contacts+=1;
        std::cout << "New contact added -> " << getNickName(_nb_contacts - 1) << std::endl;
    }
}

void PhoneBook::search( void ) {
    int num = -1;
    std::cout << "     Index" << "|";
    std::cout << "First Name" << "|";
    std::cout << " Last Name" << "|";
    std::cout << "  Nickname" << std::endl;

    for (int i = 0; i < _nb_contacts; i++) {
        std::cout << "         " << i + 1 << "|"; 
        std::cout << std::setw(10) << contacts->format(getFirstName(i)); 
        std::cout << "|";
        std::cout << std::setw(10) << contacts->format(getLastName(i));
        std::cout << "|";
        std::cout << std::setw(10) << contacts->format(getNickName(i));
        std::cout << "\n";
    }
    while (num <= 0 || num >= 9) {
        std::string res;
        while (!res.length()) {
            std::cout << "Please type the contact you want to reach:\n";
            std::getline(std::cin, res);
            if (std::cin.eof())
                exit(EXIT_SUCCESS);
            if (res.length() != 1 || !isdigit(res[0])) {
                std::cout << "Warning: expected a single digit." << "\n";
                break;
            }
            num = std::stoi(res);
        }
        if (num != -1 && (num <= 0 || num >= 9))
            std::cout << "Warning: Out of range (1->8)" << std::endl;
        if (num != -1) {
            num = std::stoi(res);
        }
    }
    if (getFirstName(num - 1).empty() == false) {
        std::cout << "First Name: " << getFirstName(num - 1) << std::endl;
        std::cout << "Last Name: " << getLastName(num - 1) << std::endl;
        std::cout << "Nick Name: " << getNickName(num - 1) << std::endl;
        std::cout << "Phone Number: " << getPhoneNumber(num - 1) << std::endl;
        std::cout << "Darkest Secret: " << getDarkestSecret(num - 1) << std::endl;
    }
    else
        std::cout << "Warning: No contact at this index" << std::endl;
}

