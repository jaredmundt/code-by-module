// Illustrates unique_ptr in a vector
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Foo {
public:
    Foo(){}
    ~Foo() {
        cout << "destroying a Foo\n";
    }
};

int main() {
    vector<unique_ptr<Foo> > v;
    v.push_back(unique_ptr<Foo>(new Foo));
    v.push_back(unique_ptr<Foo>(new Foo));
    v.push_back(unique_ptr<Foo>(new Foo));

}

/* Output:
destroying a Foo
destroying a Foo
destroying a Foo
*/
