#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACT 8
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
    private:
        Contact contacts[MAX_CONTACT];
        int _nb_contacts = 0;
        
    public:
        PhoneBook( void ) {};
        ~PhoneBook( void ) {};

        void add( void );
        void search( void );

        std::string getFirstName( int index );
        std::string getLastName( int index );
        std::string getNickName( int index );
        std::string getPhoneNumber( int index );
        std::string getDarkestSecret( int index );
};

#endif