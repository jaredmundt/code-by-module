#include <iostream>
using namespace std;

int main() {
    int x = 7;
    char *p = reinterpret_cast<char*>(&x);
    for (int i = 0; i < sizeof(int); ++i)
        cout << static_cast<int>(p[i]) << ' ';
    cout << endl;
}