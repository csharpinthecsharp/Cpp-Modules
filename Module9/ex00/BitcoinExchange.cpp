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

void BitcoinExchange::fillContainer( std::fstream& f, std::vector<std::string>& container ) {
    std::string line;
    while (std::getline(f, line))
        container.push_back(line);
}

std::vector<std::string> BitcoinExchange::getUserContainer() const {
    return this->_user_db;
}

std::vector<std::string> BitcoinExchange::getInternalContainer() const {
    return this->_internal_db;
}

std::ostream& operator<<( std::ostream& os, const BitcoinExchange& be ) {
    for (size_t i(0); i < be.getUserContainer().size(); i++)
        os << be.getUserContainer().at(i) << std::endl;
    return os;
}
