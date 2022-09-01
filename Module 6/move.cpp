#include <iostream>
#include <utility>
using namespace std;

class C {
public:
    C() = default;
    C(const C&) {cout << "copy constructor\n";}
    C(C&&) {cout << "move constructor\n";}
    C& operator=(const C&) {cout << "copy assignment\n";}
    C& operator=(C&&) {cout << "move assignment\n";}
};

C g() {return C();}

void f(C) {}

int main() {
    C c;
    C c2(c);
    c = c2;
    c = g();
    f(c);
    f(g());     // Optimized away
    f(std::move(g()));
}

/* Output:
copy constructor
copy assignment
move assignment
copy constructor
move constructor
*/