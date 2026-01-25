#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _grade(LOW_GRADE), _name("Default_Bureaucrat") {
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

const int Bureaucrat::getGrade() const {
    return _grade;
}

const std::string Bureaucrat::getName() const {
    return _name;
}

void Bureaucrat::incrementGrade() {
    _grade -= 1;
    if (this->getGrade() < HIGH_GRADE)
        throw GradeTooHighException();
    else if (this->getGrade() > LOW_GRADE)
        throw GradeTooLowException();
}

void Bureaucrat::decrementGrade() {
    _grade += 1;
    if (this->getGrade() < HIGH_GRADE)
        throw GradeTooHighException();
    else if (this->getGrade() > LOW_GRADE)
        throw GradeTooLowException();
}

void Bureaucrat::signForm( AForm& fm ) {
    if (this->getGrade() <= fm.getGradeSigned() && !fm.getSigned())
        std::cout << this->getName() << " signed " << fm.getName() << std::endl;
    else
        std::cout << this->getName() << " couldn't sign " << fm.getName() << " because ";
        fm.beSigned(*this);
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << this->getName() << " failed to execute " << form.getName()
        << " because " << e.what();
    }
}


const char* Bureaucrat::GradeTooHighException::what() const noexcept {
    return "Grade is too High";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
    return "Grade is too Low";
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bt ) {
    os << bt.getName() << ", bureaucrat grade " << bt.getGrade();
    return os;
}



