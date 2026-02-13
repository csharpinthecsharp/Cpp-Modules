#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _container;
    public:
        Span();
        Span( unsigned int N );
        ~Span();
        Span( const Span& sn );
        Span &operator=( const Span& sn );

        void addNumber( int nb );
        void addNumbers( std::vector<int>::iterator f, std::vector<int>::iterator l);
        int shortestSpan() const;
        int longestSpan() const;
        std::vector<int> getContainer() const;

        class SpanBlankException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Span don't have any value exception";
                }
        };

        class MaxElementsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Max elements exception";
                }

        };
};

std::ostream &operator<<( std::ostream& os, const Span& sn );

#endif