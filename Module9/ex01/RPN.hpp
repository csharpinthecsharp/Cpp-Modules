#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <exception>

class RPN {
    private:
        std::stack<int> _stack;
    public:
        RPN( const std::string& list );
        ~RPN();
        RPN( const RPN& rn );
        RPN &operator=( const RPN& rn );

        bool isValidElement( char elm );
        void addElements( std::string list );
        int calculation( char elm, int a, int b);
        void handleNextSpace( const std::string& list, size_t *i);

        const std::stack<int>& getStack() const;

        class EmptyListException : public std::exception {
            virtual const char* what() const throw() {
                return "Error: list is empty.";
            }            
        };

        class WrongElementListException : public std::exception {
            virtual const char* what() const throw() {
                return "Error: wrong element inside the list.";
            }            
        };

        class MissingSpaceBetweenElementsExpection : public std::exception {
            virtual const char* what() const throw() {
                return "Error: missing space between element.";
            }            
        };
};

std::ostream &operator<<( std::ostream& os, const RPN& rn );

#endif