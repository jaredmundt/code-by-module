#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class MyObject {
    int id;
    string name;
public:
    MyObject(int i = 0, const string& nm = "") : name{nm}, id{i} {}
    friend ostream& operator<<(ostream&, const MyObject&);
    friend istream& operator>>(istream&, MyObject&);
};

ostream& operator<<(ostream& os, const MyObject& o) {
    return os << '{' << o.id << ',' << o.name << '}';
}

istream& operator>>(istream& is, MyObject& o) {
    // Consume {
    char c = ' ';
    is >> c;
    if (c != '{')
        is.setstate(ios::failbit);

    // Read id
    int id;
    is >> id;

    // Consume comma
    is >> c;
    if (c != ',')
        is.setstate(ios::failbit);

    // Read name
    string name;
    while (is >> c && isalpha(c))
        name += c;
    if (c != '}')
        is.setstate(ios::failbit);

    // Update object
    if (is) {
        o.id = id;
        o.name = name;
    }
    return is;
}

int main() {
    string input{"{100,john}"};
    istringstream is(input);
    MyObject m;
    is >> m;
    cout << m << endl;  // {100,john}
}