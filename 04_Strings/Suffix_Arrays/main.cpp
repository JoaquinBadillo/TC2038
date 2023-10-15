#include <string>
#include <iostream>
#include "./lib/utils.hpp"

int main(int argc, char const *argv[]) {
    std::string s;

    if (argc > 1) {
        s = argv[1];
    } else {
        std::cout << "Enter a string: " << std::endl;
        std::cin >> s;
    }

    SuffixArray sa(s);
    std::cout << sa << std::endl;

    return 0;
}
