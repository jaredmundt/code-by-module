// array.cpp
#include <array>
#include <cassert>
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    enum {N = 5};
    array<int, N> a = {1,2,3,4}; 
    cout << sizeof(a) << endl;      // 20
    cout << a.size() << endl;       // 5
    for (auto x: a)
        cout << x << ' ';           // 1 2 3 4 0
    cout << endl;
    
    array<int, N> b;
    b = a;                          // Array assignment
    assert(b == a);
    b[4] = 5;
    assert(b != a);
    for (auto x: b)
        cout << x << ' ';           // 1 2 3 4 5
    cout << endl;

    cout << typeid(begin(a)).name() << endl;
}

/* Output:
20
5
1 2 3 4 0 
1 2 3 4 5
Pi 
*/