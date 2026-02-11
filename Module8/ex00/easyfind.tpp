#include "easyfind.hpp"

template <typename T> typename T::iterator easyfind(T& container, int value) {
    typename T::iterator ir;
    
    ir = std::find(container.begin(), container.end(), value);
    if (ir != container.end())
        return ir;
    throw OccurenceNotFoundException();
}