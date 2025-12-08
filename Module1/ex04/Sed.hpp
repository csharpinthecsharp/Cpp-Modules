#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream> 

class Sed {
    private:
        std::string _filename;
        std::string _s1;
        std::string _s2;
    public:
        Sed( std::string fn, std::string s1, std::string s2 );
        ~Sed( void );

        bool isExist( void );
};

#endif