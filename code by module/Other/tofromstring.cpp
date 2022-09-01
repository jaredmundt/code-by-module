#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<class T>
T fromString(const string& s) {
    istringstream is(s);
    T t;
    is >> t;
    return t;
}

template<class T>
string toString(const T& t) {
    ostringstream os;
    os << t;
    return os.str();
}

int main() {
    double x = 7.2;
    string s(toString(x));
    cout << s << '\n';
    double y = fromString<double>(s);
    cout << y << '\n';
}