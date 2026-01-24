#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: _target("Default_RobotomyRequestForm"),
AForm("Default_RobotomyRequestForm", 72, 45) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string& target )
: _target(target),
AForm(target, 72, 45) {
    std::cout << "RobotomyRequestForm param constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& rf ) {
    *this = rf;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm& rf ) {
    if (this != &rf) {
        this->_target = rf._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute( const Bureaucrat& executor ) const {
    if (!this->getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExecute())
        throw GradeTooHighException();
    std::cout << "BAM BAM BAM LE CHANTIER EST EN COURS!" << std::endl;
    std::cout << "LE GROS ROBOT EST EN CHANTIERRRRR!!!!" << std::endl;
    srand(time(NULL));
    if (rand() % 2) {
        std::cout << _target << " HAVE BEEN ROBOTIZEDDDD !!!!!!!" << std::endl;
        return ;
    }
    std::cout << "ROBOTOMY FAILED :(" << std::endl;
    return ;
}