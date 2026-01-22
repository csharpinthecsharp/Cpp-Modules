#ifndef FORM_HPP
#define FORM_HPP

#define LOW_GRADE 150
#define HIGH_GRADE 1

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        const int _grade_signed;
        const int _grade_execute;
        bool _signed;
    public:
        Form();
        Form( const std::string& name, const int grade_s, const int grade_e);
        ~Form();
        Form( const Form& fm );
        Form &operator=( const Form& fm );

        const int getGradeSigned() const;
        const int getGradeExecute() const;
        const std::string getName() const;
        const bool getSigned() const;

        void beSigned( const Bureaucrat& bt );

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const noexcept override;
        };
        class FormAlreadySignedException : public std::exception {
            public:
                const char* what() const noexcept override;
        };
};

std::ostream& operator<<( std::ostream& os, const Form& fm );

#endif