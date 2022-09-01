#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s("Now is the time!");
    for (auto iter = begin(s); iter != end(s); ++iter)
        *iter = toupper(*iter);
    cout << s << endl;      // NOW IS THE TIME!

    for (auto& c: s)
        c = tolower(c);
    cout << s << endl;      // now is the time!
}