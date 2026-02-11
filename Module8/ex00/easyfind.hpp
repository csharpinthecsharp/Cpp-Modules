#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template <typename T> typename T::iterator easyfind(T& container, int value);

class OccurenceNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Occurence not found!";
        }
};
#endif