#include "Harl.hpp"

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger" << std::endl;
    std::cout << "I really do!" << std::endl;
    std::cout << "" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
    std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
    std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << "" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I've been coming for years, whereas you started working here just last month" << std::endl;
    std::cout << "" << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << "" << std::endl;
}

void Harl::ml_complain( int request ) {
    void ( Harl::*pmf[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    while (request < 4) {
        (this->*pmf[request])();
        request++;
    }
}

void Harl::complain( std::string level ) {
    std::string complain_arr[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    int request;
    for (int i = 0; i < complain_arr->length(); i++) {
        if (complain_arr[i] == level)
            request = i;
    }

    switch (request) {
        case 0:
            ml_complain(0);
            break;
        case 1:
            ml_complain(1);
            break;
        case 2:
            ml_complain(2);
            break;
        case 3:
            ml_complain(3);
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
            break;
    }
}