// array.cpp
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
using namespace std;

template<typename T, size_t N>
void f(const array<T,N>& a) {
    cout << a.size() << endl;
}

int main() {
    enum {N = 5};
    array<int, N> a = {1,2,3,4};
    cout << typeid(a).name() << endl;
    cout << sizeof(a) << endl;
    copy(a.begin(), a.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    cout << a.size() << endl;
    
    array<int, N> b;
    b = a;
    assert(b == a);
    b[4] = 5;
    assert(b != a);
    copy(b.begin(), b.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    
    f(b);
}

/* Output:
St5arrayIiLm5EE
20
1 2 3 4 0 
5
1 2 3 4 5 
5
*/