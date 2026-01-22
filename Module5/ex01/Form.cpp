#include "Form.hpp"

Form::Form()
: _name("Default_Form"),
_signed(false),
_grade_signed(150),
_grade_execute(150) {
    std::cout << "Form constructor called" << std::endl;
}

Form::Form( const std::string& name, const int grade_s, const int grade_e )
: _name(name),
_signed(false),
_grade_signed(grade_s),
_grade_execute(grade_e) {
    if (_grade_signed < HIGH_GRADE)
        throw GradeTooHighException();
    if (_grade_signed > LOW_GRADE)
        throw GradeTooLowException();
    std::cout << "Form param constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

Form::Form( const Form& fm )
: _grade_signed(fm._grade_signed),
_grade_execute(fm._grade_execute),
_name(fm._name) {
    *this = fm;
}

Form &Form::operator=( const Form& fm ) {
    if (this != &fm) {
        this->_signed = fm._signed;
    }
    return *this;
}
    
const int Form::getGradeSigned() const {
    return this->_grade_signed;
}

const int Form::getGradeExecute() const {
    return this->_grade_execute;
}

const std::string Form::getName() const {
    return this->_name;
}

const bool Form::getSigned() const {
    return this->_signed;
}

void Form::beSigned( const Bureaucrat& bt ) {
    if (this->getSigned()) { 
        throw FormAlreadySignedException();
        return ;
    }
    if (bt.getGrade() > this->getGradeExecute()) {
        throw GradeTooLowException();
        return ;
    }
    this->_signed = true;
    return ;
}

const char* Form::GradeTooHighException::what() const noexcept {
    return "grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept {
    return "grade is too low";
}

const char* Form::FormAlreadySignedException::what() const noexcept {
    return "form is already signed";
}

std::ostream &operator<<( std::ostream& os, const Form& fm ) {
    os << " " << std::endl;
    os << "=== " << fm.getName() << " ===" << std::endl;
    os << "Signed: " << fm.getSigned() << std::endl;
    os << "Grade: " << fm.getGradeSigned() << std::endl;
    os << "Grade_Execute: " << fm.getGradeExecute() << std::endl;
    os << "=== END ===" << std::endl;
    return os;
}
