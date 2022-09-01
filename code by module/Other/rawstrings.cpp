// rawstrings.cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = R"(a\\b\n)";
    string t = R"|(a = "(b + c)")|";  // extra delimiter
    cout << s << endl;  // a\\b\n
    cout << t << endl;  // a = "(b + c)"
}