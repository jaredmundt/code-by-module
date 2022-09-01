#include <iostream>
using namespace std;

class IBase {
public:
    virtual ~IBase() = default;
    virtual void theAlgorithm() = 0;
};

class Base : public IBase {
    void fixedop1() { cout << "fixedop1\n"; }
    void fixedop2() { cout << "fixedop2\n"; }
public:
    void theAlgorithm() override final {
        fixedop1();
        missingop1();
        fixedop2();
        missingop2();
    }
protected:
    virtual void missingop1() = 0;
    virtual void missingop2() = 0;
};

class Derived : public Base {
    void missingop1() override {
        cout << "missingop1\n";
    }
    void missingop2() override {
        cout << "missingop2\n";
    }
};

int main() {
    Derived d;
    d.theAlgorithm();
}

/* Output:
fixedop1
missingop1
fixedop2
missingop2
*/
