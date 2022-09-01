// capturethis.cpp: Shows how to capture class members
#include <functional>
#include <iostream>
#include <string>
using namespace std;

class Foo {
    string s;
public:
    Foo(const string& s) : s(s) {}
    function<string(void)> greet() {
        return [this]{return "hello " + s;};
    }
};

int main() {
    Foo f("Larry");
    auto g = f.greet();
    cout << g() << endl;    // hello Larry
    cout << f.greet()() << endl;
}