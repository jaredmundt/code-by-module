// bindmem.cpp: Shows how to bind a member function
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::placeholders;

class Foo {
    int x;
public:
    Foo(int n) : x(n) {}
    int f() const {return x;}                   // Call as x.f()
    int g(int y) const {return x+y;}            // Call as x.g(n)
    void display() const {cout << x << endl;}   // Call as x.display()
};

int main() {
    Foo obj(5);
    auto f1 = bind(&Foo::f,_1);     // Leave object ptr free
    cout << f1(obj) << endl;        // 5
    auto f2 = bind(&Foo::g,obj,_1); // Fix object, leave g's arg free
    cout << f2(3) << endl;          // 8
    auto f3 = [&obj](int y){return obj.g(y);};
    
    array<Foo,3> a = {Foo(1),Foo(2),Foo(3)};
    for_each(a.begin(),a.end(),bind(&Foo::display,_1));
    
    vector<Foo*> v = {new Foo(4), new Foo(5)};
    for_each(v.begin(),v.end(),bind(&Foo::display,_1)); // Just works!
    for_each(v.begin(),v.end(),[](const Foo* p){p->display();});    // Use -> explicitly)
    for_each(v.begin(),v.end(),[](Foo* p){delete p;});  // Clean-up
}

/* Output:
5
8
1
2
3
4
5
*/