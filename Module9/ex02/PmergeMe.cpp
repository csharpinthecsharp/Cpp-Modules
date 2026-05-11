#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}


void mergingVector();
std::vector<PmergeMe::Pair>& PmergeMe::getVector() {
    return (this->_v_seq);
}
 

std::deque<PmergeMe::Pair>& PmergeMe::getDeque() {
    return (this->_d_seq);
}

const PmergeMe::Pair& PmergeMe::getPair() const
{
    return this->_pair;
}

std::ostream &operator<<(std::ostream& os, const PmergeMe &other) {
    os << "Before: " << std::endl;
    os << "After: " << std::endl;
    os << "Time to process a range of " << std::endl;
    os << "Time to process a range of " << std::endl;
}
