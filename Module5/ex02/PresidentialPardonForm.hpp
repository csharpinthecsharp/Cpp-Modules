#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm( const std::string& target );
        PresidentialPardonForm( const PresidentialPardonForm& pf );
        PresidentialPardonForm &operator=( const PresidentialPardonForm& pf );
        ~PresidentialPardonForm();

        virtual void execTrigger() const;
};

#endif