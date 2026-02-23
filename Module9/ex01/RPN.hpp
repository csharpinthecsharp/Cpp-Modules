#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>

class RPN {
    private:
        std::stack<int> _stack;
    public:
        RPN();
        ~RPN();
        RPN( const RPN& rn );
        RPN &operator=( const RPN& rn );

        bool isValidElement( char elm );
        void addElements( std::string list );
        int calculation( char elm, int a, int b);

        const std::stack<int>& getStack() const;
};

std::ostream &operator<<( std::ostream& os, const RPN& rn );

#endif