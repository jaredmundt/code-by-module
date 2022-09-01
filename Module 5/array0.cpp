#include <array>
#include <cstddef>
#include <iostream>
using namespace std;

template<size_t N>
void add1(array<int,N>& a) {
    for (int& n: a)
        ++n;
}

int main() {
    array<int,5> a{1,2,3,4};
    add1(a);
    for (auto n: a)
        cout << n << ' ';   // 2 3 4 5 1 
    cout << endl;
}