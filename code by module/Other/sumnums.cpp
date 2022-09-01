// sumnums.cpp: Sums numbers read from standard input (cin)
#include <iostream>
using namespace std;

int main() {
    int sum = 0, value = 0;
    while (cin >> value)
        sum += value;
    cout << "sum: " << sum << endl;
}