#include <iostream>
using namespace std;

class A {
protected:
    int x = 1;
};

class B : public A {
public:
    void display() const {
        cout << "x = " << x << endl;
    }
    void f() const {
        A a;
        cout << "x = " << a.x << endl;      // Error
    }
};

int main() {
    B b;
    b.display();
}

/* Compiler output:
error: 'int A::x' is protected
*/