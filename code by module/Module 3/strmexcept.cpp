// strmexcept.cpp: Shows how to use exceptions with input streams
#include <cassert>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    ios::iostate sstate = cin.exceptions(); // Save exceptions settings
    cin.exceptions(istream::failbit);
    cout << "Enter a non-numeric string... ";
    int n = 7;
    try {
        cin >> n;
        cout << n << endl;
    }
    catch (...) {
        cout << "stream error" << endl;
    }
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Eat up to newline
    cin.exceptions(sstate);
    cout << "Enter a non-numeric string... ";
    cin >> n;
    if (!cin) {
        cout << "stream error\n";
        cin.clear();
    }
    else
        cout << n << endl;
}

/* Sample execution:
Enter a non-numeric string... abc
stream error
Enter a non-numeric string... abc
stream error
*/