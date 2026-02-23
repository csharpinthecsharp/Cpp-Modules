#include "RPN.hpp"

RPN::RPN() : _stack() {

}

RPN::~RPN() {

}

RPN::RPN( const RPN& rn ) {
    *this = rn;
}

RPN &RPN::operator=( const RPN& rn ) {
    (void)rn;
    return *this;
}

bool RPN::isValidElement( char elm ) {
    if (elm == '+' || elm == '-' || elm == '*' || elm == '/')
        return true;
    return false;
}

void RPN::addElements( std::string list ) {
    int a;
    int b;
    for (size_t i(0); list[i]; ++i) {
        if (isValidElement(list[i])) {
            a = _stack.top();
            _stack.pop();
            b = _stack.top();
            _stack.pop();
            _stack.push(calculation(list[i], a, b));
        }
        else if (isspace(list[i]))
            continue;
        else if (isdigit(list[i]))
            _stack.push(static_cast<int>(list[i] - '0'));
        else {
            std::cout << "Error: " << list[i] << std::endl;
            exit(1);
        }
    }
}

int RPN::calculation( char elm, int a, int b) {
    switch (elm) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return (0);
    }   
}

const std::stack<int>& RPN::getStack() const {
    return _stack;
}


std::ostream &operator<<( std::ostream& os, const RPN& rn ) {
    os << rn.getStack().top() << std::endl;
    return os;
}

