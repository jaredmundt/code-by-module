// Shows the problem with default args in both overrides and base
#include <iostream>
using namespace std;

class A {
protected:
    int x;
public:
    A(int theX) {
        x = theX;
    }
    virtual int add(int y = 1) {
        return x + y;
    }
};

class B : public A {
public:
    B(int theX) : A(theX) {}
    int add(int y = 2) {
        return 2*x + y;
    }
};

int main() {
    B b(5);
    cout << b.add() << endl;    // 12 (2*5 + 2)
    B* p1 = &b;
    cout << p1->add() << endl;  // 12 (2*5 + 2)
    A* p2 = &b;
    cout << p2->add() << endl;  // 11 (2*5 + 1)  WRONG?
}