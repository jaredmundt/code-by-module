#include <iostream>
using namespace std;

class Int {
    int x;
public:
    Int() {
        cout << "initializing an Int\n";
        x = 0;
    }
    void display() const {
        cout << "Int::x: " << x << '\n';
    }
};

class Foo {
    int n;
    Int t;
public:
    Foo() : n() {}      // Zero-initialization
    void display() const {
        cout << "n: " << n << '\n';
        cout << "t: ";
        t.display();
    }
};

int main() {
    Foo f;
    f.display();
}

/* Output:
initializing an Int
n: 0
t: Int::x: 0
*/