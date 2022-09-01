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
    int n;	// C++11 only
    Int t;
public:
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

/* Outut:
initializing an Int
n: 0
t: Int::x: 0
*/