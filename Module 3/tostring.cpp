#include <iostream>
#include <string>       // Defines std::to_string
using namespace std;

int main() {
    double x = 7.2;
    string s = to_string(x);
    cout << s << endl;   // 7.200000
    s = to_string(true);
    cout << s << endl; 
    cout << true << '\n' << boolalpha << true << '\n';
}

