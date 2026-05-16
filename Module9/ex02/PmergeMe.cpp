#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}

bool sortComparePair( const PmergeMe::Pair& p1, const PmergeMe::Pair& p2 ) {
    return (p1.b < p2.b);
}

std::vector<PmergeMe::Pair>& PmergeMe::getVector() {
    return (this->_v_seq);
}

std::deque<PmergeMe::Pair>& PmergeMe::getDeque() {
    return (this->_d_seq);
}

const PmergeMe::Pair& PmergeMe::getPair() const {
    return (this->_pair);
}
 
std::vector<int>& PmergeMe::getMainVector() {
    return (this->_v_main);
}

std::deque<int>& PmergeMe::getMainDeque() {
    return (this->_d_main);
}

std::vector<int>& PmergeMe::getWaitVector() {
    return (this->_v_wait);
}

std::deque<int>& PmergeMe::getWaitDeque() {
    return (this->_d_wait);
}

std::ostream &operator<<(std::ostream& os, PmergeMe &other) {
    os << "Before: ";
    for (std::vector<PmergeMe::Pair>::iterator it = other.getVector().begin(); it !=  other.getVector().end(); ++it)
        os << it->a << " " << it->b << " ";
    os << std::endl;
    os << "After: ";
    for (std::vector<int>::iterator it = other.getMainVector().begin(); it !=  other.getMainVector().end(); ++it)
        os << *it  << " ";
    return os;
}
