#include <iostream>
#include <string>
using namespace std;

int main() {
    string n("10");
    string x("7.2");
    
    cout << stoi(n) << endl;    // 10
    cout << stol(n) << endl;    // 10
    cout << stoul(n) << endl;   // 10
    cout << stoll(n) << endl;   // 10
    cout << stoull(n) << endl;  // 10
    
    // Real to int
    cout << stoi(x) << endl;    // 7
    
    // Reals
    cout << stof(n) << endl;    // 10
    cout << stod(n) << endl;    // 10
    cout << stold(n) << endl;   // 10
    
    // Different bases
    n = "1011";
    cout << stoi(n,nullptr,2) << endl;    // 11
    n = "1F";
    cout << stoi(n,nullptr,16) << endl;   // 31
}