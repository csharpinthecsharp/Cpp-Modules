#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void wrong_grade_test() {
    std::cout << "\n=== WRONG GRADE TEST ===" << std::endl;
    try {
        Bureaucrat bt(138, "Georges");
        Bureaucrat be(46, "Gaboo");
        Bureaucrat bs(26, "Zapy");
        ShrubberyCreationForm sh("Gregoire");
        RobotomyRequestForm rf("RobotAlpha");
        PresidentialPardonForm pf("Criminel");

        try {
            bt.signForm(sh);
            sh.execute(bt);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        try {
            be.signForm(rf);
            rf.execute(be);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        try {
            bs.signForm(pf);
            pf.execute(bs);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=== END OF WRONG GRADE TEST ===\n" << std::endl;
}

void unsigned_test() {
    std::cout << "\n=== UNSIGNED TEST ===" << std::endl;
    try {
        Bureaucrat bt(135, "Georges");
        Bureaucrat be(12, "Gaboo");
        Bureaucrat bs(4, "Zapy");
        ShrubberyCreationForm sh("Gregoire");
        RobotomyRequestForm rf("RobotAlpha");
        PresidentialPardonForm pf("Criminel");

        try {
            sh.execute(bt);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        try {
            rf.execute(be);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        try {
            pf.execute(bs);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=== END OF UNSIGNED TEST ===\n" << std::endl;
}

void signed_test() {
    std::cout << "\n=== SIGNED TEST ===" << std::endl;
    try {
        Bureaucrat bt(135, "Georges");
        Bureaucrat be(12, "Gaboo");
        Bureaucrat bs(4, "Zapy");
        ShrubberyCreationForm sh("Gregoire");
        RobotomyRequestForm rf("RobotAlpha");
        PresidentialPardonForm pf("Criminel");

        try {
            bt.signForm(sh);
            bt.executeForm(sh);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        try {
            be.signForm(rf);
            be.executeForm(rf);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        try {
            bs.signForm(pf);
            pf.execute(bs);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "=== END OF SIGNED TEST ===\n" << std::endl;
}

int main() {
    signed_test();
    unsigned_test();
    wrong_grade_test();
}