#include "Phonebook.hpp"

Contact::Contact(std::string f_n, std::string l_n, std::string nn, std::string pn, std::string ds) {
    _first_name = f_n;
    _last_name = l_n;
    _nickname = nn;
    _phone_number = pn;
    _darkest_secret = ds;
}

std::string Contact::getFirstName( void ) {
    return (_first_name);
}

std::string Contact::getLastName( void ) {
    return (_last_name);
}

std::string Contact::getNickName( void ) {
    return (_nickname);
}

std::string Contact::getPhoneNumber( void ) {
    return (_phone_number);
}

std::string Contact::getDarkestSecret( void ) {
    return (_darkest_secret);
}

void Contact::create( void ) {
    this->_first_name = ask_user("first name");
    this->_last_name = ask_user("last name"); 
    this->_nickname = ask_user("nickname"); 
    this->_phone_number = ask_user("phone number");
    this->_darkest_secret = ask_user("darkest secret");
}

std::string Contact::ask_user( std::string name ) {
    std::string res;
    while (!res.length()) {
        std::cout << "Please type the " << name << " :\n";
        std::getline(std::cin, res);
        if (std::cin.eof())
            exit(EXIT_SUCCESS);
        if (!res.length()) {
            std::cout << "Warning: empty field is not authorized." << "\n";
        }
    }
    return res;
}

std::string Contact::format( std::string string ) {
    if (string.length() > 10)
        return string.substr(0, 9) + ".";
    return string;
}