// gtnf.cpp: A gtn function with a lambda return (closure)
#include <functional>
#include <iostream>
using namespace std;

function<int(int)> gtn(int n) {
    return [n](int m){return m > n;};
}

int main() {
    auto f = gtn(5);
    cout << f(4) << endl;   // 0
    cout << f(6) << endl;   // 1
}