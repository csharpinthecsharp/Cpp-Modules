#include "iter.hpp"

int main( void ) {
    int _i_arr[3] = {
        0,
        1,
        2
    };
    size_t _si_array = sizeof(_i_arr) / sizeof(_i_arr[0]);


    std::string _s_array[5] = {
        "f0",
        "f1",
        "f2",
        "f3",
        "f4"
    };
    size_t _ss_array = sizeof(_s_array) / sizeof(_s_array[0]);

    const char _c_array[3] = {
        'a',
        'b',
        'c',
    };
    size_t _cs_array = sizeof(_c_array) / sizeof(_c_array[0]);

    ::iter(_i_arr, _si_array, &exec);
    ::iter(_s_array, _ss_array, &exec);
    ::iter(_c_array, _cs_array, &exec);
    return 0;
}