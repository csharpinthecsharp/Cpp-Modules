#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>

class ScalarConverter {
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter( const ScalarConverter& sr );
        ScalarConverter &operator=( const ScalarConverter& sr );
    public:
        static void convert( const std::string& str );
};

#endif