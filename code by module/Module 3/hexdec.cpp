#include <iostream>
using namespace std;

int main() {
    ostream hexout(cout.rdbuf());   // Prints to same place as cout
    hexout << hex;
    cout << 48 << endl;     // 48
    hexout << 48 << endl;   // 30
}
