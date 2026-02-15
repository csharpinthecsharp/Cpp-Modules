#include "MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack() {

}

template <typename T> MutantStack<T>::~MutantStack() {

}

template <typename T> MutantStack<T>::MutantStack( const MutantStack& mk ) {
    *this = mk;
}

template <typename T> MutantStack<T> &MutantStack<T>::operator=( const MutantStack& mk ) {
    (void)mk;
    return *this;
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}
template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}