#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe() {

}

bool sortComparePair( const PmergeMe::Pair& p1, const PmergeMe::Pair& p2 ) {
    return (p1.b < p2.b);
}

void PmergeMe::mergingVector(int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        mergingVector(start, mid);
        mergingVector(mid + 1, end);
        mergeRec(start, mid, end);
    }
}

void PmergeMe::mergeRec(int left, int mid, int right) {
    std::vector<Pair> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (_v_seq[i].b <= _v_seq[j].b) {
            temp[k++] = _v_seq[i++];
        } else {
            temp[k++] = _v_seq[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = _v_seq[i++];
    }
    while (j <= right) {
        temp[k++] = _v_seq[j++];
    }
    for (int p = 0; p < k; p++) {
        _v_seq[left + p] = temp[p];
    }
}

void PmergeMe::buildChain() {
    if (_v_seq.empty())
        throw "Error: empty chain";
    this->_main.push_back(_v_seq[0].a);
    for (std::vector<Pair>::iterator it = this->_v_seq.begin(); it != this->_v_seq.end(); ++it)
        this->_main.push_back(it->b);
    for (std::vector<Pair>::iterator it = this->_v_seq.begin() + 1; it != this->_v_seq.end(); ++it)
        this->_wait.push_back(it->a);
}

void PmergeMe::InsertionVector() {
    for (std::vector<int>::iterator it = this->_wait.begin(); it !=  this->_wait.end(); ++it) {
        std::vector<int>::iterator pos = std::lower_bound(this->_main.begin(), this->_main.end(), *it);
        _main.insert(pos, *it);
    }
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

const std::vector<int>& PmergeMe::getMainVector() const {
    return (this->_main);
}

std::ostream &operator<<(std::ostream& os, const PmergeMe &other) {
    for (std::vector<int>::const_iterator it = other.getMainVector().begin(); it !=  other.getMainVector().end(); ++it)
        os << *it << std::endl;
    return os;
    /*
    os << "Before: " << std::endl;
    os << "After: " << std::endl;
    os << "Time to process a range of " << std::endl;
    os << "Time to process a range of " << std::endl;*/
}
