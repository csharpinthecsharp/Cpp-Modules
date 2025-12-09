#include "Harl.hpp"

void Harl::panel( void ) {
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Welcome Harl, what is you complain today ?" << std::endl;
    std::cout << "[0]: debug" << std::endl;
    std::cout << "[1]: info" << std::endl;
    std::cout << "[2]: warning" << std::endl;
    std::cout << "[3]: error" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "$> ";

}

void Harl::debug( void ) {
    std::cout << "I received my paycheck." << std::endl;
}

void Harl::info( void ) {
    std::cout << "It's been 2 days that im waiting for my paycheck, just to let you know." << std::endl;
}

void Harl::warning( void ) {
    std::cout << "Im waiting too long for this mf paycheck, pay me or i will sue you!" << std::endl;
}

void Harl::error( void ) {
    std::cout << "3 MONTHS WAITING TO BE PAYED, YOUR COOKED IM KILLING YOU MONDAY.." << std::endl;
}

void Harl::complain( std::string level ) {
    void ( Harl::*pmf[4] )() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    
    int levelAsInt = 0;
    if (isdigit(level[0]) && (level[0] - '0') < 4)
        levelAsInt = level[0] - '0';
    (this->*pmf[levelAsInt])();
}