#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "ERROR.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate( void ) {
    int r = rand() % 4;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else if (r == 2)
        return new C;
    else 
        return new ERROR;
}
void identify( Base* p ) {
    Base* a_ptr = dynamic_cast<A*> (p);
    if (a_ptr != NULL) {
        std::cout << a_ptr << std::endl;
        return ;
    }
    Base* b_ptr = dynamic_cast<B*> (p);
    if (b_ptr != NULL) {
        std::cout << b_ptr << std::endl;
        return ;
    }
    Base* c_ptr = dynamic_cast<C*> (p);
    if (c_ptr != NULL) {
        std::cout << c_ptr << std::endl;
        return ;
    }
    std::cout << "*Type is invalid" << std::endl;
}

void identify( Base& p) {
    try {
        Base& a_ptr = dynamic_cast<A&> (p);
        std::cout << &a_ptr << std::endl;
    }
    catch (std::exception & e) {
        try {
            Base& b_ptr = dynamic_cast<B&> (p);
            std::cout << &b_ptr << std::endl;
        }
        catch (std::exception & e) {
            try {
                Base& c_ptr = dynamic_cast<C&> (p);
                std::cout << &c_ptr << std::endl;
            }
            catch (std::exception & e) {
                std::cout << "&Type is invalid" << std::endl;
            }    
        }    
    }
}

int main() {
    std::srand(std::time(NULL));
    Base *base = generate();
    identify(*base);
    identify(base);
    delete base;
}