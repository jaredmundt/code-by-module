#include <vector>
#include <iostream>
using namespace std;

struct Foo {
    Foo(int en, const string& ess) : n(en), s(ess) {
        cout << "Making Foo with: " << s << endl;
    }
    Foo(const Foo& f) : n(f.n), s(f.s) {
	    cout << "Copying Foo from: " << s << endl;
    }
    int n;
    string s;
};

int main() {
    vector<Foo> v;
    v.reserve(5);
    v.emplace_back(1,"one");
    Foo f (2, "two");
    v.push_back (f);

}

