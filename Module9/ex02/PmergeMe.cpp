#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}

bool sortComparePair( const PmergeMe::Pair& p1, const PmergeMe::Pair& p2 ) {
    return (p1.b < p2.b);
}

void PmergeMe::mergingVector()
{
    std::sort(_v_seq.begin(), _v_seq.end(), sortComparePair);
}

void PmergeMe::buildMainChain() {
    if (_v_seq.empty())
        throw "Error: empty chain";
    this->_main.push_back(_v_seq[0].a);
    for (std::vector<Pair>::iterator it = this->_v_seq.begin(); it != this->_v_seq.end(); ++it)
        this->_main.push_back(it->b);
    for (std::vector<Pair>::iterator it = this->_v_seq.begin() + 1; it != this->_v_seq.end(); ++it)
        this->_wait.push_back(it->a);
}

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
