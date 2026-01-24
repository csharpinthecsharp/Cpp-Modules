#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm( const std::string& target );
        RobotomyRequestForm( const RobotomyRequestForm& rf );
        RobotomyRequestForm &operator=( const RobotomyRequestForm& rf );
        ~RobotomyRequestForm();

        virtual void execTrigger() const;
};

#endif