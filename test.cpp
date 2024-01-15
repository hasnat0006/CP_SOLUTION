#include <iostream>
#include <string>
#include <vector>

std::vector<int> base5(int n) {
    std::vector<int> result;
    if (n == 0)
        return result;
    while (n > 0) {
        result.push_back(n % 5);
        n /= 5;
    }
    return result;
}

int seq(int n) {
    std::vector<int> base5Result = base5(n);
    int result = 0;
    for (int i = base5Result.size() - 1; i >= 0; --i) {
        result = result * 10 + 2 * base5Result[i];
    }
    return result;
}

int main() {
    for (int i = 0; i < 100; ++i) {
        std::cout << i << " " << seq(i) << std::endl;
    }
    return 0;
}
