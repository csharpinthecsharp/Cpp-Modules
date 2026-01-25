#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm( const std::string& target );
        ShrubberyCreationForm( const ShrubberyCreationForm& sf );
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm& sf );
        ~ShrubberyCreationForm();

        void execute( const Bureaucrat& executor ) const;

};

#endif