#include <cassert>
#include <iostream>
#include <typeinfo>
using namespace std;

class B {
public:
    virtual ~B(){}
};

class D : public B {};

class D2 : public D {};

int main() {
    D2 d;
    assert(dynamic_cast<D*>(&d));
    assert(dynamic_cast<B*>(&d));
    B* p = &d;
    cout << typeid(p).name() << endl;
    cout << typeid(*p).name() << endl;
}


