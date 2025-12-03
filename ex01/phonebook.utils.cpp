#include "phonebook.header.hpp"

bool ft_is_singledigit(std::string input)
{
    int len = input.length();
    for (int i = 0; i < len; i++) {
        if (i == 1)
            return false;
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}