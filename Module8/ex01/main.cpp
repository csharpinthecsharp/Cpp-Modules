#include "Span.hpp"

int main() {
        Span sn = Span(10500);
        try { 
            for (size_t i(0); i < 5; i++)
                sn.addNumber(i);
            std::cout << sn << std::endl;
            std::cout << "Longest span: " << sn.longestSpan() << std::endl;        
            std::cout << "Shortest span: " << sn.shortestSpan() << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }

        std::vector<int> mlt;
        for (int i (0); i < 10000; i++)
            mlt.push_back(i);

        try { 
            sn.addNumbers(mlt.begin(), mlt.end());
            std::cout << sn << std::endl;
            std::cout << "Longest span: " << sn.longestSpan() << std::endl;        
            std::cout << "Shortest span: " << sn.shortestSpan() << std::endl;
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
}