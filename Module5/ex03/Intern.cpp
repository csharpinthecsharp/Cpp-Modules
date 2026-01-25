#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern( const Intern& in ) {
    *this = in;
    std::cout << "Intern copy constructor called" << std::endl;

}

Intern &Intern::operator=( const Intern& in ) {
    std::cout << "Intern copy assignment operator called" << std::endl;
    return *this;
}

AForm *Intern::internMakeRobot( const std::string& target ) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::internMakePresident( const std::string& target ) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::internMakeShrubbery( const std::string& target ) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm( std::string name, std::string target ) {
    std::string formNames[3] {
        "robotomy request",
        "presidential pardon",
        "shrubbery creation",
    };

    AForm* ( Intern::*pmf[3] )(const std::string&) = {
        &Intern::internMakeRobot,
        &Intern::internMakePresident,
        &Intern::internMakeShrubbery
    };

    for (int i = 0; i < 3; i++) {
        if (formNames[i] == name) {
            std::cout << "Intern created a " << name <<
                " form, with target " << target << std::endl;
            return (this->*pmf[i])(target);
        }
    }
    std::cout << "Intern cannot create form, name not found" << std::endl;
    return NULL;
}

