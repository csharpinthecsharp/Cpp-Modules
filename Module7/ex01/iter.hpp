#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T> void iter(T* array_ptr, T* array_size) {
    for (int i(0); i < *array_size; i++)
        std::cout << array_ptr[i] << std::endl;
}

#endif