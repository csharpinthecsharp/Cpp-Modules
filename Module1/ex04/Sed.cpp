#include "Sed.hpp"

Sed::Sed( std::string fn, std::string s1, std::string s2 ) {
    _filename = fn;
    _s1 = s1;
    _s2 = s2;
}

Sed::~Sed( void ) {
}

bool Sed::isExist( void ) {
    std::ofstream def_file( _filename, std::ios::in );
    if (def_file.good()) {
        std::cout << "Sucess, file exist." << std::endl;
        return true;
    }
    std::cout << "Error, file don't exist." << std::endl;
    return false;
}

/*
basic_ios::fail
    Check whether failbit or badbit is set (public member function)

basic_ios::good
    Check whether state of stream is good (public member function)

basic_ios::bad
    Check whether badbit is set (public member function)

basic_ios::eof
    Check whether eofbit is set (public member function)

basic_ios::rdstate
    Get error state flags (public member function)

basic_ios::clear
    Set error state flags (public member function)*/