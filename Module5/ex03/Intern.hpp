#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        Intern( const Intern& in );
        Intern &operator=( const Intern& in );

        AForm* internMakeRobot( const std::string& target );
        AForm* internMakePresident( const std::string& target );
        AForm* internMakeShrubbery( const std::string& target );
        AForm* makeForm( std::string name, std::string target );
};

#endif