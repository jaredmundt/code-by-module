#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "1234,\"Billy Bob\"";
    cout << s << '\n';                  // 1234,"Billy Bob"
    cout << quoted(s) << '\n';          // "1234,\"Billy Bob\""
    istringstream istr(s);
    string num, name;

    getline(istr,num,',');
    int number = stoi(num);
    istr >> quoted(name);  
    cout << num << '\n';                // 1234
    cout << name << '\n';               // Billy Bob
    cout << quoted(name) << '\n';       // "Billy Bob"
    cout << quoted(name,'@') << '\n';   // @Billy Bob@

    s = "hello\nthere";
    cout << s << '\n';                  /* hello
                                           there */
    cout << s.size() << '\n';           // 11
    cout << quoted(s) << '\n';          /* "hello
                                           there" */
    cout << int(s[5]) << '\n';          // 10 (newline ascii code)
    ostringstream ostr;
    ostr << quoted(s);
    cout << ostr.str().size() << '\n';  // 13
}