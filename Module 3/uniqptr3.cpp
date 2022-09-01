// uniqptr3.cpp: Uses unique_ptr with an array
// Probably rarely needed (use std::array or std::vector instead)

#include <iostream>
#include <memory>

using namespace std;

class Foo {
public:
    Foo(){}
    ~Foo() {
        cout << "destroying a Foo\n";
    }
};

int main() {
    unique_ptr<Foo[]> p(new Foo[3]);
}

/* Output:
destroying a Foo
destroying a Foo
destroying a Foo
*/
