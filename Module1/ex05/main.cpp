#include "Harl.hpp"

int main( int ac, char **av ) {
    Harl harl;
    harl.panel();

    std::string str_cmpl;
    std::getline( std::cin, str_cmpl );
    if (std::cin.eof() || std::cin.bad())
        return 0;

    harl.complain( str_cmpl );
    return 0;
}