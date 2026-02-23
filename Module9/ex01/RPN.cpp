#include "RPN.hpp"

RPN::RPN( const std::string& list ) : _stack() {
    if (list.empty()) 
        throw EmptyListException();
    addElements(list);
}

RPN::~RPN() {

}

RPN::RPN( const RPN& rn ) {
    *this = rn;
}

RPN &RPN::operator=( const RPN& rn ) {
    if (this != &rn) {
        this->_stack = rn._stack;
    }
    return *this;
}

bool RPN::isValidElement( char elm ) {
    if (elm == '+' || elm == '-' || elm == '*' || elm == '/')
        return true;
    return false;
}

void RPN::handleNextSpace( const std::string& list, size_t *i ) {
    if ((list.size() - 1) > *i) {
        if (isspace(list[*i + 1]))
            ++*i;
        else
            throw MissingSpaceBetweenElementsExpection();
    }    
}

void RPN::addElements( std::string list ) {
    int a;
    int b;
    for (size_t i(0); list[i]; ++i) {
        if (isValidElement(list[i])) {
            a = this->_stack.top();
            this->_stack.pop();
            b = this->_stack.top();
            this->_stack.pop();
            this->_stack.push(calculation(list[i], a, b));
            handleNextSpace(list, &i);
        }
        else if (isdigit(list[i])) {
            this->_stack.push(static_cast<int>(list[i] - '0'));
            handleNextSpace(list, &i);
        }
        else
            throw WrongElementListException();
    }
}

int RPN::calculation( char elm, int a, int b) {
    switch (elm) {
    case '+':
        return b + a;
    case '-':
        return b - a;
    case '*':
        return b * a;
    case '/':
        return b / a;
    default:
        throw WrongElementListException();
    }   
}

const std::stack<int>& RPN::getStack() const {
    return _stack;
}


std::ostream &operator<<( std::ostream& os, const RPN& rn ) {
    os << rn.getStack().top();
    return os;
}

