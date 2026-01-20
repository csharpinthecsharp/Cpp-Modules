#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(LOW_GRADE), _name("Default") {
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( unsigned int grade, const std::string& name )
: _grade(grade), _name(name) {
    if (grade < HIGH_GRADE)
        throw GradeTooHighException();
    if (grade > LOW_GRADE)
        throw GradeTooLowException();
    std::cout << "Bureaucrat param constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade is too High";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade is too Low";
}


