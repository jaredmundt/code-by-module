#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<class T>
string toString(const T& t) {
    ostringstream os;
    os << t;
    return os.str();
}

int main() {
    double x = 7.2;
    cout << to_string(x) << endl;   // 7.200000
    cout << toString(x) << endl;    // 7.2

    int n = 7;
    cout << to_string(n) << endl;   // 7
    cout << toString(n) << endl;    // 7
}