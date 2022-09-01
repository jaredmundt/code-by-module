#include <iostream>
using namespace std;

class Foo {
    int n;
public:
    Foo(int m) {
        n = m;
    }
    template<class T>
    void bar(T t) {
        cout << "n == " << n << ", your value: " << t << endl;
    }
};

class Baz {
public:
    friend ostream& operator<<(ostream& os, const Baz& b) {
        return os << "Baz object";
    }
};

int main() {
    Foo f(10);
    f.bar("twenty");
    f.bar(Baz());
}
