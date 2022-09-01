#include <iostream>
using namespace std;

void print_bin(unsigned short n) {
    unsigned short mask = 1u << 15;
    while (mask) {
        cout << !!(mask & n);
        mask >>= 1;
    }
    cout << endl;
}

int main() {
    unsigned short n = 100;
    print_bin(n);
    n >>= 1;
    print_bin(n);
    n = ~n;
    print_bin(n);
    print_bin(n & ~n);
    print_bin(n | ~n);
    print_bin(n ^ ~n);

}