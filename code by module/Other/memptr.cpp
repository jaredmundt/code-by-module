#include <iostream>
using namespace std;

class C
{
public:
    void f() {cout << "C::f\n";}
    void g() {cout << "C::g\n";}
};

int main()
{
    C c;
    
    // Using an object
    void (C::*pmf)() = &C::f;
    (c.*pmf)();     // Executes c.f()
    pmf = &C::g;
    (c.*pmf)();     // Executes c.g()
    
    // Using pointer to an object
    C* cp = &c;
    pmf = &C::f;
    (cp->*pmf)();   // Executes cp->f()
    pmf = &C::g;
    (cp->*pmf)();   // Executes cp->g()
}

/* Output:
C::f
C::g
C::f
C::g
*/
