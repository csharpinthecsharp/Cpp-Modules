#ifndef BITCOINEXCHANGE_CPP
#define BITCOINEXCHANGE_CPP

#include <iostream>
#include <fstream>
#include <exception>
#include <vector>
#include <algorithm>

class BitcoinExchange {
    private:
        std::string _input;
        std::vector<std::string> _internal_db;
        std::vector<std::string> _user_db;
    public:
        BitcoinExchange( const std::string& input );
        ~BitcoinExchange();

        static void isGoodFormat( char **input, int size );
        void handleUserDataBase();
        void handleInternalDataBase();
        void calculation();

        std::fstream& openStream( const std::string& input, std::fstream& f );
        void fillContainer( std::fstream& f, std::vector<std::string>& container );

        std::vector<std::string> getUserContainer() const;
        std::vector<std::string> getInternalContainer() const;

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