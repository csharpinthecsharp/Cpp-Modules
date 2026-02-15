#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <exception>
#include <iostream>
#include <algorithm>
#include <list>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
    public: 
        MutantStack();
        ~MutantStack();
        MutantStack( const MutantStack& mk );
        MutantStack &operator=( const MutantStack& mk );

        typedef typename std::deque<T>::iterator iterator;

        // en gros on sors les containers interne de std::stack.
        iterator begin();
        iterator end();
};

#endif