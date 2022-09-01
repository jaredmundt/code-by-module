// See map2.cpp for a non-C++17 version (replaces the structured binding with first/second)
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Insert some elements (three ways):
    map<string, string> m;
    m.insert(make_pair("Alabama","Montgomery"));
    m.insert({"Tennessee","Knoxville"});
    m["Georgia"] = "Atlanta";
    m["Tennessee"] = "Nashville";
    m.emplace("Michigan","Lansing");	// Uses constructor args to create the pair on-the-fly

    // Print the map:
    for (auto [k,v]: m)     // Stuctured Binding (C++17)
        cout << '{' << k << ',' << v << "}\n";
    cout << endl;

    // finding
    cout << (m.find("Georgia"))->second << endl;

    if (m.find("Texas") != m.end())
	    cout << "Found Texas" << endl;
    else
	    cout << "Texas isn't in the map" << endl;
}
