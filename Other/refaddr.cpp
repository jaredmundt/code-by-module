// refaddr.cpp: Shows a feature of pass-by-reference
#include <iostream>
using namespace std;

void f(int x) {
    cout << &x << endl;
}

void g(int& x) {
    cout << &x << endl;
}

int main() {
    int n;
    cout << &n << endl;
    f(n);
    g(n);
}

/* Output:
0x7fff5fbff9ac
0x7fff5fbff98c
0x7fff5fbff9ac
*/