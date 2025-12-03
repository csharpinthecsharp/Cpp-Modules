#ifndef PHONEBOOK_HEADER_HPP
#define PHONEBOOK_HEADER_HPP

#include <string>
#include "phonebook.class.hpp"

std::string get_single(std::string name);
Contact get_infos();
int get_num();
bool is_singledigit(std::string input);
std::string transform_string(std::string string);

#endif