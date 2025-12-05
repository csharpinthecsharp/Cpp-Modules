#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

#define MAX_CONTACT 8
#include "phonebook.header.hpp"
#include "contact.class.hpp"

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