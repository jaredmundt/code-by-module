#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<7> b;
    cout << b << endl;

    b.set(0);
    cout << b << endl;
    for (int i = 0; i < 7; i += 2)
        b.set(i);
    cout << b << endl;

    for (int i = 0; i < 7; ++i)
        b.flip(i);
    cout << b << endl;
}

/* Output:
0000000
0000001
1010101
0101010
*/