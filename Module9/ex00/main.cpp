#include "BitcoinExchange.hpp"

int main( int ac, char **av) {
    try {
        BitcoinExchange::isGoodFormat(av, ac);
        BitcoinExchange be(av[1]);
        be.handleInternalDataBase();
        be.handleUserDataBase();
        be.calculation();
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
}