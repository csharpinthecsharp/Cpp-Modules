#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#define LOW_GRADE 150
#define HIGH_GRADE 1

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat( unsigned int grade, const std::string& name );
        ~Bureaucrat();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const noexcept override;
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const noexcept override;
        };
};

#endif