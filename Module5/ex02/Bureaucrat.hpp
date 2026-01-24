#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#define LOW_GRADE 150
#define HIGH_GRADE 1
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    protected:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat( unsigned int grade, const std::string& name );
        ~Bureaucrat();

        const int getGrade() const;
        const std::string getName() const;
        void incrementGrade();
        void decrementGrade();

        void signForm( AForm& fm );

        class GradeTooHighException : std::exception {
            public:
                const char* what() const noexcept override;
        };

        class GradeTooLowException : std::exception {
            public:
                const char* what() const noexcept override;
        };
};

std::ostream& operator<<( std::ostream& os, const Bureaucrat& bt );

#endif