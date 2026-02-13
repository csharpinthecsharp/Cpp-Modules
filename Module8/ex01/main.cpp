#include "Span.hpp"

int main() {
        Span sn = Span(5);
        try { 
            for (size_t i(0); i < 5; i++)
                sn.addNumber(i);
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << sn << std::endl;
        std::cout << "Longest span: " << sn.longestSpan() << std::endl;        
        std::cout << "Shortest span: " << sn.shortestSpan() << std::endl;
}