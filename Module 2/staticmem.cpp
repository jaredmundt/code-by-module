// Illustrate initializing static member data

#include <iostream>
using namespace std;

class Foo {
public:
    static int n;
};

int Foo::n; // Try commenting this out

int main(){
    cout << Foo::n << endl;     // 0
}