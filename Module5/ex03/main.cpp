#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat bt(1, "Tester");
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        bt.signForm(*rrf);
        bt.executeForm(*rrf);
        delete rrf;
    }
    return (0);
}