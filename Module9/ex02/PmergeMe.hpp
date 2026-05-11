#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

//https://medium.com/@toukmati2000/cpp09-ford-johnson-algorithm-e6ad43288d4b

class PmergeMe {
    public:
        struct Pair {
            int a;
            int b;
        };   
        Pair _pair;
    private:
        std::vector<Pair> _v_seq;
        std::deque<Pair> _d_seq;
    public:     
        PmergeMe();
        ~PmergeMe();

        void mergingVector();
        void InsertionVector();
        std::vector<Pair> &getVector();

        void mergingDeque();
        void InsertionDeque();
        std::deque<Pair> &getDeque();

        const Pair& getPair() const;
};

std::ostream &operator<<(std::ostream& os, const PmergeMe &other);

#endif