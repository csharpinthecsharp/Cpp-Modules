#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Data;

class Serializer {
    private:
        Serializer();
        Serializer( const Serializer& sr );
        Serializer &operator=( const Serializer& sr );
        ~Serializer();
    public:
        static uintptr_t serialize( Data* ptr );
        static Data* deserialize( uintptr_t raw );
};

#endif