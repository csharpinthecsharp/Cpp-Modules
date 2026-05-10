#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}

std::vector<int>& PmergeMe::getVector() {
    return (this->_v_seq);
}
 

std::deque<int>& PmergeMe::getDeque() {
    return (this->_d_seq);
}

std::ostream &operator<<(std::ostream& os, const PmergeMe &other) {
    os << "Before: " << std::endl;
    os << "After: " << std::endl;
    os << "Time to process a range of " << std::endl;
    os << "Time to process a range of " << std::endl;
}
