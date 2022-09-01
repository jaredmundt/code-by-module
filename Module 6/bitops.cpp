// bitops.cpp: Extracts IEEE components
#include <iostream>
using namespace std;

int main() {
    float x = 6.5;
    unsigned int n = *reinterpret_cast<unsigned int*>(&x);
    cout << hex << n << endl;           // 40d00000
    int sb = n >> 31;
    cout << sb << endl;                 // 0

    unsigned int expmask = ((1u << 8) - 1) << 23;
    cout << expmask << endl;            // 7f800000
    int exp = (n & expmask) >> 23;
    cout << dec << exp << endl;         // 129
    cout << ((n << 1) >> 24) << endl;   // 129 (another way)

    int mask4 = 1u << 4;
    n |= mask4;                         // Set bit 4
    cout << hex << n << endl;           // 40d00010
    n &= ~mask4;                        // Clear it
    cout << hex << n << endl;           // 40d00000
}

