#include <iostream>
using namespace std;

class Foo {
public:
   void f() const {cout << "Foo::f\n";}
   void g() const {cout << "Foo::g\n";}
};

template<class T>
void exec(const T& f, void (T::*p)() const) {
   (f.*p)();
}

template<class T, class FType>
void exec2(const T& f, FType p) {
   (f.*p)();
}

int main() {
   Foo foo;
   exec(foo, &Foo::f);
   exec2(foo, &Foo::g);
}

/* Output:
Foo::f
Foo::g
*/

