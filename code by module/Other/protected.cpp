#include <iostream>
using namespace std;

class A {
    int x;
protected:
    void f() const {
        cout << x << endl;
    }
public:
    A(int theX) {
        x = theX;
    }
};

class B : public A {
public:
    B(int theX) : A(theX) {}
    void g() const {
        f();
    }
};
class C : public B {
public:
    C(int theX) : B(theX) {}
    void h() const {
        f();
    }
};

int main() {
    B b(1);
    b.g();
    C c(2);
    c.h();
}