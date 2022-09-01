 // sharedptr.cpp: Creates multiple pointers to a single object by
//                 passing by value
#include <memory>
#include <iostream>
using namespace std;

struct Foo {
    int x;
};

void g(shared_ptr<Foo> p) {
    cout << p.use_count() << '\n';
    cout << p->x << '\n';
    p->x = 30;
}

void f(shared_ptr<Foo> p) {
    cout << p.use_count() << '\n';
    p->x = 20;
    g(p);
}

int main() {
    shared_ptr<Foo> p(new Foo);
    cout << p.use_count() << '\n';
    p->x = 10;
    f(p);
    cout << p.use_count() << '\n';
    cout << p->x << '\n';
}

/* Output:
1
2
3
20
1
30
*/