#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    {
        try {
            Bureaucrat bt(32,"Kevin");
            Form fm("Test", 1, 50);
            std::cout << fm << std::endl;
            try {
                bt.signForm(fm);
            }
            catch ( std::exception & e) {
                std::cout << e.what() << std::endl;
            }
            std::cout << fm << std::endl;

            try {
                bt.signForm(fm);
            }
            catch ( std::exception & e) {
                std::cout << e.what() << std::endl;
            }
            std::cout << fm << std::endl;
        }
        catch ( std::exception & e ) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            Bureaucrat bt(100,"Kevin");
            Form fm("Test", 1, 50);
            std::cout << fm << std::endl;
            try {
                bt.signForm(fm);
            }
            catch ( std::exception & e) {
                std::cout << e.what() << std::endl;
            }
            std::cout << fm << std::endl;
        }
        catch ( std::exception & e ) {
            std::cout << e.what() << std::endl;
        }
    }
}