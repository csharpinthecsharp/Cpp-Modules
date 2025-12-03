#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#define MAX_CONTACT 8
#include <iostream>

class Contact
{
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

        Contact( void ) {}; // Default constructor
        ~Contact( void ) {}; // Destructor

        Contact getter( void );
        std::string formater( std::string& string );

        Contact(std::string f_n, std::string l_n, std::string nn, std::string pn, std::string ds) {
            first_name = f_n;
            last_name = l_n;
            nickname = nn;
            phone_number = pn;
            darkest_secret = ds;
        } // Parameterized Constructor
};

class PhoneBook
{
    public:

        PhoneBook( void ) {};
        ~PhoneBook( void ) {};
        
        Contact contacts[MAX_CONTACT];
        int nb_contacts = 0;

        void add(const Contact& c);
        void search( void );
};

#endif