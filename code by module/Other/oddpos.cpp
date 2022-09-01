// oddpos.cpp: Illustrates mututally recursive functions
#include <iostream>
#include <string>
using namespace std;

// A function declaration (not a definition)
string oddpos(const string&);

string evenpos(const string s) {
    if (s.size() == 0)
        return s;
    return s[0] + oddpos(s.substr(1));
}

string oddpos(const string& s) {
    if (s.size() <= 1)
        return ""s;
    return evenpos(s.substr(1));
}

int main() {
    cout << oddpos("hello") << '\n';
    cout << evenpos("hello") << '\n';
}