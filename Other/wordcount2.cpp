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

    for (const auto& [k,v]: m)		// Structured Binding
        cout << k << ": " << v << '\n';
}
