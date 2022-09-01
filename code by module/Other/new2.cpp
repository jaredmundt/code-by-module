#include <iostream>
using namespace std;

int main() {
    auto p = new int [2][3];
    cout << sizeof(p) << endl;          // 8
    cout << typeid(p).name() << endl;   // PA3_i
    cout << sizeof(*p) << endl;         // 12
    cout << typeid(*p).name() << endl;  // A3_i
}