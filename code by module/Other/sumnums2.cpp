// sumnums2.cpp: Sums numbers read from standard input (cin)
#include <iostream>

int main() {
    int sum = 0, value = 0;
    while (std::cin >> value)
        sum += value;
    std::cout << "sum: " << sum << std::endl;
}