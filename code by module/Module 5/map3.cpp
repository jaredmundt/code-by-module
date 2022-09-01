// See map2.cpp for a non-C++17 version (replaces the structured binding with first/second)
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct structcmp {
	bool operator() (const string& s1, const string& s2) const {
		return s1 > s2; }
};


int main()
{
    // Insert some elements (three ways):
    map<string, string, structcmp> m;
    m.insert(make_pair("Alabama","Montgomery"));
    m.insert({"Tennessee","Knoxville"});
    m["Georgia"] = "Atlanta";
    m["Tennessee"] = "Nashville";
    m.emplace("Michigan","Lansing");	// Uses constructor args to create the pair on-the-fly

    // Print the map:
    for (auto [k,v]: m)     // Stuctured Binding (C++17)
        cout << '{' << k << ',' << v << "}\n";
    cout << endl;

    // Retrieve via a key:
    cout << '"' << m.at("Georgia") << '"' << endl;
    try {
        cout << m.at("Texas") << endl;
    }
    catch (...) {
        cout << "Texas not in map\n";
    }
}
