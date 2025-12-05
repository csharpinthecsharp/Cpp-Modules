#include "phonebook.header.hpp"

Contact Contact::getter( void )
{
    Contact c("", "", "", "", "");
    c.first_name = get_single("first name");
    c.last_name = get_single("last name");
    c.nickname = get_single("nickname");
    c.phone_number = get_single("phone number");
    c.darkest_secret = get_single("darkest secret");
    return c;
}

std::string Contact::formater( std::string& string )
{
    if (string.length() > 10)
        return string.substr(0, 9) + ".";
    return string;
}