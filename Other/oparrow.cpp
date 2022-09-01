#include <iostream>
using namespace std;

struct Foo {int x; int y;};

class FooWrapper {
    Foo* pf;
public:
    FooWrapper(Foo* p) : pf(p) {}
    Foo* operator->() {
        cout << "returning a Foo*\n";
        return pf;
    }
};

int main() {
    Foo f = {1,2};
    FooWrapper fw(&f);
    cout << fw->x << '\n';
    cout << fw->y << '\n';
}

/* Output:
returning a Foo*
1
returning a Foo*
2
*/