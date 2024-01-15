#include <iostream>
#include <string>

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;
    std::string substring = "FBFFBFFBFB";
    if (substring.find(input) != std::string::npos) {
        std::cout << "The input string is a substring of \"FBFFBFFBFB\"" << std::endl;
    } else {
        std::cout << "The input string is not a substring of \"FBFFBFFBFB\"" << std::endl;
    }
    return 0;
}