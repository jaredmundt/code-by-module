#include <iostream>
using namespace std;

int main() {
    int a[] = {9,4,77,50};
    int* p = a;
    cout << p[2] << endl;
    p += 2;
    cout << p[0] << endl;
    cout << p[-1] << endl;
    cout << 1[p] << endl;
    cout << p - a << endl;
    cout << p << endl;
    cout << a << endl;
}