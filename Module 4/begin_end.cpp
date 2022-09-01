#include <iostream>
#include <string>
using namespace std;

int main() {
    string s("hello");
    for (auto p = begin(s); p != end(s); ++p)
        cout << *p;
    cout << endl;
    
    int a[] = {1,2,3,4,5};
    for (auto p = begin(a); p != end(a); ++p)
        cout << *p << ' ';
    cout << endl;
}

/* Output:
hello
1 2 3 4 5 
*/
