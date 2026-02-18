#ifndef BITCOINEXCHANGE_CPP
#define BITCOINEXCHANGE_CPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <algorithm>
#include <string>
#include <cstdlib>

#define BAD_INPUT -1
#define NOT_POSITIVE -2
#define TOO_LARGE -3

class BitcoinExchange {
    private:
        std::string _input;
        std::map<std::string, float> _internal_db;
        std::map<std::string, float> _user_db;
    public:
        BitcoinExchange( const std::string& input );
        ~BitcoinExchange();

        static void isGoodFormat( char **input, int size );
        void handleUserDataBase();
        void handleInternalDataBase();
        void calculation();

        std::fstream& openStream( const std::string& input, std::fstream& f );
        void fillContainer( std::fstream& f, std::map<std::string, float>& container );
        const std::map<std::string, float>& getUserContainer() const;
        const std::map<std::string, float>& getInternalContainer() const;

        class NoInputFileException : public std::exception {
            virtual const char* what() const throw() {
                return "Error: no input file.";
            }
        };

        class CouldNotOpenFileException : public std::exception {
            virtual const char* what() const throw() {
                return "Error: could not open file.";
            }
        };
};

std::ostream& operator<<( std::ostream& os, const BitcoinExchange& be ); 

#endif