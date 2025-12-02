#include "phonebook.class.hpp"

bool ft_isdigit(std::string input)
{
    int len = input.length();
    for (int i = 0; i < len; i++) {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}