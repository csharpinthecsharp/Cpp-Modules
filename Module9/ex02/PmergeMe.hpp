#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <exception>
#include <ctime>

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

        std::deque<int> _d_main;
        std::vector<int> _v_main;

        std::vector<int> _v_wait;
        std::deque<int> _d_wait;

        std::time_t d_time;
        std::time_t v_time;
        int _elm;
    public:     
        PmergeMe();
        ~PmergeMe();

        template <typename T> void merging(T& container, int start, int end);
        template <typename T> void mergeRec(T& container, int left, int mid, int right);
        template <typename T, typename T_INT> void buildChain(T& container, T_INT& main, T_INT& wait);
        template <typename T_INT> void insertion(T_INT& main, T_INT& wait);
        std::vector<Pair> &getVector();
        std::deque<Pair> &getDeque();
        const Pair& getPair() const;

        std::vector<int> &getMainVector();
        std::deque<int> &getMainDeque();

        std::vector<int> &getWaitVector();
        std::deque<int> &getWaitDeque();

        void updateTime( std::time_t time, int flag );
        std::time_t getTime( int flag ) const;

        void updateElm( int n );
        int getElm() const;

        class NonPositiveArgument : public std::exception {
            virtual const char* what() const throw() {
                return "Error: non pos arguments";
            }
        };
};

std::ostream &operator<<(std::ostream& os, PmergeMe &other);

template <typename T> void PmergeMe::merging(T& container, int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merging(container, start, mid);
        merging(container, mid + 1, end);
        mergeRec(container, start, mid, end);
    }
}

template <typename T> void PmergeMe::mergeRec(T& container, int left, int mid, int right) {
    T temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (container[i].b <= container[j].b) {
            temp[k++] = container[i++];
        } else {
            temp[k++] = container[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = container[i++];
    }
    while (j <= right) {
        temp[k++] = container[j++];
    }
    for (int p = 0; p < k; p++) {
        container[left + p] = temp[p];
    }
}

template <typename T, typename T_INT> void PmergeMe::buildChain(T& container, T_INT& main, T_INT& wait) {
    main.push_back(container[0].a);
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
        main.push_back(it->b);
    for (typename T::iterator it = container.begin() + 1; it != container.end(); ++it)
        wait.push_back(it->a);
}

template <typename T_INT> void PmergeMe::insertion(T_INT& main, T_INT& wait) {
    for (typename T_INT::iterator it = wait.begin(); it !=  wait.end(); ++it) {
        typename T_INT::iterator pos = std::lower_bound(main.begin(), main.end(), *it);
        main.insert(pos, *it);
    }
}

#endif