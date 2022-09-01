// swo.cpp: Ilustrates a strict weak ordering
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
using namespace std;

// The following function object compares strings by ignoring all non-letters
struct LettersOnly {
    bool operator()(const string& s1, const string& s2) const {
        string one, two;

        // Remove non-alpha characters for comparison
        auto alpha = [](char c){return isalpha(c);};
        copy_if(s1.begin(), s1.end(), back_inserter(one), alpha);
        copy_if(s2.begin(), s2.end(), back_inserter(two), alpha);

        return one < two;   // A SWO ("less"); Change this to <= and see what happens!
    }
};

int main() {
    set<string, LettersOnly> stuff;
    stuff.insert("A Man, A Plan, A Canal, Panama");
    stuff.insert("AManAPlanACanalPanama");  // ignored
    cout << stuff.size() << endl;           // 1
    for_each(stuff.begin(),stuff.end(),[](const string& s){cout << s << endl;});
}

/* Output:
1
A Man, A Plan, A Canal, Panama
*/