#include "AForm.hpp"

AForm::AForm()
: _name("Default_Form"),
_signed(false),
_grade_signed(150),
_grade_execute(150) {
    std::cout << "Form constructor called" << std::endl;
}

AForm::AForm( const std::string& name, const int grade_s, const int grade_e )
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

AForm::~AForm() {
    std::cout << "Form destructor called" << std::endl;
}

AForm::AForm( const AForm& fm )
: _grade_signed(fm._grade_signed),
_grade_execute(fm._grade_execute),
_name(fm._name) {
    *this = fm;
}

AForm &AForm::operator=( const AForm& fm ) {
    if (this != &fm) {
        this->_signed = fm._signed;
    }
    return *this;
}
    
const int AForm::getGradeSigned() const {
    return this->_grade_signed;
}

const int AForm::getGradeExecute() const {
    return this->_grade_execute;
}

const std::string AForm::getName() const {
    return this->_name;
}

const bool AForm::getSigned() const {
    return this->_signed;
}

void AForm::beSigned( const Bureaucrat& bt ) {
    if (this->getSigned()) { 
        throw FormAlreadySignedException();
        return ;
    }
    if (bt.getGrade() > this->getGradeSigned()) {
        throw GradeTooLowException();
        return ;
    }
    this->_signed = true;
    return ;
}

void AForm::execute( Bureaucrat const& executor ) {
    if (!this->getSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGradeExecute())
        throw GradeTooHighException();
    this->execTrigger();  
}

const char* AForm::GradeTooHighException::what() const noexcept {
    return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const noexcept {
    return "grade is too low";
}

const char* AForm::FormAlreadySignedException::what() const noexcept {
    return "form is already signed";
}

const char* AForm::FormNotSignedException::what() const noexcept {
    return "form is not signed";
}

std::ostream &operator<<( std::ostream& os, const AForm& fm ) {
    os << " " << std::endl;
    os << "=== " << fm.getName() << " ===" << std::endl;
    os << "Signed: " << fm.getSigned() << std::endl;
    os << "Grade: " << fm.getGradeSigned() << std::endl;
    os << "Grade_Execute: " << fm.getGradeExecute() << std::endl;
    os << "=== END ===" << std::endl;
    return os;
}
