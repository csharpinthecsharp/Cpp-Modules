#include <iostream>
#include <cctype>

void print_noise() {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
        << '\n';
}

std::string g_new_arg(const std::string& arg) {
    std::string str;
    for (char c: arg)
    {
        if (islower(c))
            str += toupper(c);
        else
            str += c;
    }
    return (str);
}

int main(int argc, char **argv) {
    if (argc < 2)
    {
        print_noise();
        return (0);
    } 
    std::string str;    
    for (int i = 1; i < argc; i++)
        str.append(g_new_arg(argv[i]));
    std::cout << str << '\n';
}
