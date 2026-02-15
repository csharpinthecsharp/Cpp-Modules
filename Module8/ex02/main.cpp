#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main() {
    std::cout << "=== MutantStack ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "" << std::endl;
    std::cout << "=== List ===" << std::endl;
    std::list<int> lt;
    lt.push_back(5);
    lt.push_back(17);
    std::cout << lt.back() << std::endl;
    lt.pop_back();
    std::cout << lt.size() << std::endl;
    lt.push_back(3);
    lt.push_back(5);
    lt.push_back(737);
    //[...]
    lt.push_back(0);
    std::list<int>::iterator lsit = lt.begin();
    std::list<int>::iterator lsite = lt.end();
    ++lsit;
    --lsit;
    while (lsit != lsite)
    {
        std::cout << *lsit << std::endl;
        ++lsit;
    }
    return 0;
}