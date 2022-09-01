#include <vector>
#include <iostream>
using namespace std;

struct Foo {
    Foo(int en, const string& ess) : n(en), s(ess) {}
    int n;
    string s;
};

int main() {
    vector<Foo> v;
    v.emplace_back(1,"one");
    for (auto x: v)
        cout << x.n << ", " << x.s << endl;
}

/* Output:
1, one
*/
