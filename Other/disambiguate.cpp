// disambiguate.cpp
#include <iostream>
using namespace std;

class Base1 {
public:
   virtual void f(){cout << "Base1\n";}
};

class Base2 : public virtual Base1 {
public:
   void f(){cout << "Base2\n";}
};

class Base3 : public virtual Base1 {
public:
   void f(){cout << "Base3\n";}
};

class Derived : public Base2, public Base3 {
public:
    void f() {
        Base2::f(); // Can't use "using"
    }
};

int main() {
   Derived d;
   d.f();
}
