#include <iostream>
using namespace std;

class Bar;

class Foo {
    int x;
public:
    friend class Bar;
    Foo(int n) {x = n;}
    void display() const {cout << "Foo: " << x << endl;}
};

class Bar {
    int y;
public:
    Bar(int n) {y = n;}
    void changeFoo(Foo& f) {
        f.x += y;
    }
};

int main() {
    Foo f(5);
    Bar b(6);
    b.changeFoo(f);
    f.display();
}