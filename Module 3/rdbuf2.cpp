// Opens a new stream object that shares the same buffer as cout
// Allows different stream objects to access the same output channel
#include <iostream>
using namespace std;

int main() {
    ostream hexout(cout.rdbuf());   // Prints to same place as cout
    hexout << hex;
    hexout << 48 << ' ';            // 30
    cin.get();
    cout << 48 << endl;             // 48
}
