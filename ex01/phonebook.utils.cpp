#include "phonebook.header.hpp"

bool is_singledigit(std::string input)
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

std::string transform_string(std::string string)
{
    std::string res = string;
    int len = res.length();
    int max_len = 10;
    if (len <= max_len) {
        if ((max_len - len) == 0)
            return string;
        else {
            for (int i = 0; i < (max_len - len); i++)
                res.append(" ");
        }
    }
    else {
        for (int i = 0; len >= max_len; i++) { 
            res.pop_back();
            len--;
        }
        res.append(".");
    }
    return res;
}
