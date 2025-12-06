#ifndef CONTACT_CLASS_HPP
#define CONTACT_CLASS_HPP

#include "Phonebook.hpp"
#include <iomanip>

class Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

    public:
        Contact( void ) {};
        ~Contact( void ) {};
        Contact( std::string f_n, std::string l_n, std::string nn, std::string pn, std::string ds );

        std::string getFirstName( void );
        std::string getLastName( void );
        std::string getNickName( void );
        std::string getPhoneNumber( void );
        std::string getDarkestSecret( void );

        void create( void );
        std::string ask_user( std::string name );
        std::string format( std::string string );
};

#endif