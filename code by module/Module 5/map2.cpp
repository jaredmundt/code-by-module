// Non-C++17 version
#include <functional>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Insert some elements (three ways):
    map<string, string, greater<>> m;
    m.insert(make_pair("Alabama","Montgomery"));
    m.insert({"Tennessee","Knoxville"});
    m["Georgia"] = "Atlanta";
    m["Tennessee"] = "Nashville";
    m.emplace("Michigan","Lansing");	// Uses constructor args to create the pair on-the-fly

    // Print the map:
    for (auto p: m)
        cout << '{' << p.first << ',' << p.second << "}\n";
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
