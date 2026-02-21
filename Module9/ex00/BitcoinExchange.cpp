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
    fillContainer(openStream("data.csv", temp), _internal_db, false);
}

void BitcoinExchange::handleUserDataBase() {
    std::fstream temp;
    fillContainer(openStream(_input, temp), _user_db, true);
}

bool acceptDate( std::string date ) {
    if (date.size() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str()); 
    int day = std::atoi(date.substr(8, 2).c_str());

    if (!year || !month || !day)
        return false;

    if (month <= 0 || month > 12)
        return false;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        if (month == 2) {
            if (day > 29)
                return false;
        }
    }
    else {
        if (month == 2) {
            if (day > 28)
                return false;
        }  
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30)
            return false;
    }

    if (day <= 0 || day > 31)
        return false;
    return true;
}

void BitcoinExchange::calculation() {
    // Internal container value * User container value;
    // If Internal don't have the User date, take the closest one.
    for (std::map<std::string, float>::iterator it_user = _user_db.begin(); it_user != _user_db.end(); ++it_user) {
        if (it_user->second == BAD_INPUT 
            || it_user->second == NOT_POSITIVE 
            || it_user->second == TOO_LARGE)
            continue;
        if (!acceptDate(it_user->first)) {
            it_user->second = WRONG_DATE;
            continue;
        }
        std::map<std::string, float>::iterator it = _internal_db.lower_bound(it_user->first);

        if (it != _internal_db.end() && it->first == it_user->first) {
            it_user->second *= it->second;
        } else {
            if (it == _internal_db.begin()) {
                it_user->second = NO_DATE_CLOSER;
            } else {
                --it;
                it_user->second *= it->second;
            }
        }
    }
}

std::fstream& BitcoinExchange::openStream( const std::string& input, std::fstream& f  ) {
    f.open(input.c_str());
    if (!f.is_open())
        throw CouldNotOpenFileException();
    return f;
}

char BitcoinExchange::getCsvFormat( const std::string& line ) {
    if (line == "date,exchange_rate") 
        return ',';
    if (line == "date | value")
        return '|';
    else {
        std::cout << "date | value is missing." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void BitcoinExchange::fillContainer( std::fstream& f, std::map<std::string, float>& container, bool User ) {
    std::string line;
    std::getline(f, line);
    char search_char = getCsvFormat(line);
    while (std::getline(f, line)) {
        std::string key;
        std::string value;
        size_t pos_f_space = line.find_first_of(" \t\n\r\f\v");
        line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

        size_t pos = line.find(search_char);
        if (pos == std::string::npos) {
            container[line.substr(0, pos_f_space)] = BAD_INPUT;
            continue;
        }
        key = line.substr(0, pos);
        value = line.substr(pos + 1);
        float res = static_cast<float>(strtod(value.c_str(), NULL));
        if (User && res < 0) {
            container[key] = NOT_POSITIVE; 
            continue;
        }
        if (User && res > 1000) {
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
    for (std::map<std::string, float>::const_iterator it = be.getUserContainer().begin(); it != be.getUserContainer().end(); ++it) {
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
            case WRONG_DATE:
                std::cout << "Error: date is wrong." << std::endl;
                break;
            case NO_DATE_CLOSER:
                std::cout << "Error: no date closer." << std::endl;
                break;
            default:
                os << it->first << " | " << it->second << std::endl;
        }
    }
    return os;
}
