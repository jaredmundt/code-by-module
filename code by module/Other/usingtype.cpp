#include <iostream>
using namespace std;

int main() {
    using intseq = int[5];
    intseq a;
    for (int i = 0; i < 5; ++i)
        a[i] = 5-i;
    for (int i = 0; i < 5; ++i)
        cout << a[i] << ' ';    // 5 4 3 2 1
    cout << endl;
}
