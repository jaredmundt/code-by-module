#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    string word;
    map<string, int> m;
    while (cin >> word)
        m[word]++;
        
    auto f = [](pair<string,int> p) {	// Returns void by default
        cout << p.first << ": " << p.second << '\n';
    };
    for_each(m.begin(),m.end(),f);
}