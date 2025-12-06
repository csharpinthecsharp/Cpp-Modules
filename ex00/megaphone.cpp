#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char **argv) {
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    } 
    std::string str;    
    for (int i = 1; i < argc; i++) {
        std::string n_arg = argv[i];
        for (char c: n_arg)
            str += toupper(c);
    }
    std::cout << str << std::endl;
}
