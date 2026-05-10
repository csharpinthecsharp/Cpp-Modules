#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

//https://medium.com/@toukmati2000/cpp09-ford-johnson-algorithm-e6ad43288d4b

class PmergeMe {
    private:
        std::vector<int> _v_seq;
        std::deque<int> _d_seq;
    
    public:
        PmergeMe();
        ~PmergeMe();

        void mergingVector();
        void InsertionVector();
        std::vector<int> &getVector();

        void mergingDeque();
        void InsertionDeque();
        std::deque<int> &getDeque();
};

std::ostream &operator<<(std::ostream& os, const PmergeMe &other);

#endif