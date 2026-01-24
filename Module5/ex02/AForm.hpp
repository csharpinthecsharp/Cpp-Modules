#ifndef AFORM_HPP
#define AFORM_HPP

#define LOW_GRADE 150
#define HIGH_GRADE 1

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        const int _grade_signed;
        const int _grade_execute;
        bool _signed;
    public:
        AForm();
        AForm( const std::string& name, const int grade_s, const int grade_e);
        virtual ~AForm();
        AForm( const AForm& fm );
        AForm &operator=( const AForm& fm );

        const int getGradeSigned() const;
        const int getGradeExecute() const;
        const std::string getName() const;
        const bool getSigned() const;

        void beSigned( const Bureaucrat& bt );

        virtual void execTrigger() const = 0;
        void execute( Bureaucrat const& executor );

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

        class FormNotSignedException : public std::exception {
            public:
                const char* what() const noexcept override;
        };
};

std::ostream& operator<<( std::ostream& os, const AForm& fm );

#endif