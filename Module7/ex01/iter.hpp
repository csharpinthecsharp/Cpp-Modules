#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter( T* array_ptr, size_t array_size, void (*f)(T&) ) {
    for (size_t i(0); i < array_size; ++i)
        f(array_ptr[i]);
}

template <typename T> void iter( T const* array_ptr, size_t array_size, void (*f)(T const&) ) {
    for (size_t i(0); i < array_size; ++i)
        f(array_ptr[i]);
}

template < typename T > void exec( T& ) {
    std::cout << "executed: " << f << std::endl;
}

#endif