#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: _target("Default_PresidentialPardonForm"),
AForm("Default_PresidentialPardonForm", 25, 5) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const std::string& target )
: _target(target),
AForm(target, 25, 5) {
    std::cout << "PresidentialPardonForm param constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& pf ) {
    *this = pf;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm& pf ) {
    if (this != &pf) {
        this->_target = pf._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute( const Bureaucrat& executor ) const {
    if (!this->getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExecute())
        throw GradeTooHighException();
    std::cout << _target << " have been pardoned by Zaphod Beeblebrox!!!!" << std::endl;
    return ;
}