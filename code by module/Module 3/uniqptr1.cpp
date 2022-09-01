#include <memory>
#include <iostream>
using namespace std;

class Trace {
    int x;
public:
    Trace() : x(5) { cout << "ctor\n"; }
    ~Trace() { cout << "dtor\n"; }
    int get() const { return x; }
};

int main() {
    unique_ptr<Trace> p(new Trace);
    cout << p->get() << '\n';
}

/* Output:
ctor
5
dtor
*/