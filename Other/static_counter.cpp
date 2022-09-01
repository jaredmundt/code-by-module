#include <iostream>
using namespace std;

int counter() {
    static int count = 0;
    return ++count;
}

int main() {
    for (int i = 0; i < 5; ++i)
        cout << counter() << ' ';   // 1 2 3 4 5
    cout << endl;
}