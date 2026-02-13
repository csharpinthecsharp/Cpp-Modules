#include "Span.hpp"

int main() {
        Span sn = Span(100);
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
        mlt.push_back(3);
        mlt.push_back(19);
        mlt.push_back(12);
        mlt.push_back(1);
        mlt.push_back(5);

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