// union2.cpp: Reinterprets an int as an array of bytes
#include <iomanip>
#include <iostream>
using namespace std;

union int_or_bytes {
    int n;
    char b[sizeof(int)];
};

int main() {
    int_or_bytes x;
    x.n = 31;
    cout << hex << setfill('0');
    for (size_t i = 0; i < sizeof(int); ++i)
        cout << setw(2) << int(x.b[i]);
    cout << endl;
}

/* Output:
1f000000    // instead of 0000001f (do you know why?)
*/