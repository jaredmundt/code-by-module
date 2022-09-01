#include <iostream>
using namespace std;

class Outer {
    int data;
    friend class Inner;
    class Inner {
        const Outer* p;
    public:
        Inner(const Outer* o);
        void dosomething() const;
    };
public:
    Outer(int m) {
        data = m;
    }
    void f() const {
        Inner inner(this);
        inner.dosomething();
    }
};

Outer::Inner::Inner(const Outer* o) {
    p = o;
}
void Outer::Inner::dosomething() const {
    cout << p->data << endl;
}

int main() {
    Outer outer(10);
    outer.f();
}

