#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange( const std::string& input )
: _input(input),
_internal_db(),
_user_db() {
}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::isGoodFormat( char **input, int size ) {
    if (size != 2)
        throw NoInputFileException();
    if (std::string(input[1]).empty())
        throw NoInputFileException();
}

void BitcoinExchange::handleInternalDataBase() {
    std::fstream temp;
    fillContainer(openStream("data.csv", temp), _internal_db);
}

void BitcoinExchange::handleUserDataBase() {
    std::fstream temp;
    fillContainer(openStream(_input, temp), _user_db);
}

void BitcoinExchange::calculation() {
    // Internal container value * User container value;
    // If Internal don't have the User date, take the closest one.
}

std::fstream& BitcoinExchange::openStream( const std::string& input, std::fstream& f  ) {
    f.open(input.c_str());
    if (!f.is_open())
        throw CouldNotOpenFileException();
    return f;
}

void BitcoinExchange::fillContainer( std::fstream& f, std::map<std::string, float>& container ) {
    std::string line;
    while (std::getline(f, line)) {
        std::string key;
        std::string value;

        size_t pos_f_space = line.find_first_of(" \t\n\r\f\v");
        std::remove_if(line.begin(), line.end(), isspace);

        size_t pos = line.find("|");
        if (pos == std::string::npos) {
            container[line.substr(0, pos_f_space)] = BAD_INPUT;
            continue;
        }
        
        key = line.substr(0, pos);
        value = line.substr(pos + 1);

        float res = static_cast<float>(strtod(value.c_str(), NULL));
        if (res < 0) {
            container[key] = NOT_POSITIVE; 
            continue;
        }
        if (res > 1000) {
            container[key] = TOO_LARGE; 
            continue;
        }
        container[key] = res;
    }
}

const std::map<std::string, float>& BitcoinExchange::getUserContainer() const {
    return this->_user_db;
}

const std::map<std::string, float>& BitcoinExchange::getInternalContainer() const {
    return this->_internal_db;
}

std::ostream& operator<<( std::ostream& os, const BitcoinExchange& be ) {
    for (std::map<std::string, float>::const_iterator it = be.getUserContainer().begin(); it != be.getUserContainer().end(); it++) {
        switch (static_cast<int>(it->second)) {
            case BAD_INPUT:
                std::cout << "Error: bad input => " <<  it->first << std::endl;
                break;
            case NOT_POSITIVE:
                std::cout << "Error: not a positive number." << std::endl;
                break; 
            case TOO_LARGE:
                std::cout << "Error: too large a number." << std::endl;
                break;
            default:
                os << it->first << "|" << it->second << std::endl;
        }
    }
    return os;
}
