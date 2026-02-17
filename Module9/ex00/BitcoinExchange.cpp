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
        std::size_t pos = line.find("|");
        if (pos == std::string::npos) {
            container[line] = BAD_INPUT;
            continue;
        }
        key = line.substr(0, pos);
        value = line.substr(pos + 1);

        container[key] = static_cast<float>(strtod(value.c_str(), NULL));
    }
}

std::map<std::string, float> BitcoinExchange::getUserContainer() const {
    return this->_user_db;
}

std::map<std::string, float> BitcoinExchange::getInternalContainer() const {
    return this->_internal_db;
}

std::ostream& operator<<( std::ostream& os, const BitcoinExchange& be ) {
    for (std::map<std::string, float>::iterator it = be.getUserContainer().begin(); it != be.getUserContainer().end(); it++)
        os << it->first << " | " << it->second << std::endl;
    return os;
}
