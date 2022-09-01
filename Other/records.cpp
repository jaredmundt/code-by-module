// Defines a strict-weak comparator for a map of records

#include <map>
#include <iostream>
#include <string>
using namespace std;

struct Key {
    string last;
    string first;
    Key() = default;
    Key(const Key&) = default;
    Key(string&& lst, string&& frst) : last(lst), first(frst) {}
};

struct Value {
    string address;
    string city;
    string zip;
    Value() = default;
    Value(const Value&) = default;
    Value(const string& addr, const string& cty, const string& zp) : address(addr), city(cty), zip(zp) {}
};

struct Comp {
    bool operator()(const Key& key1, const Key& key2) const {
        if (key1.last != key2.last)
            return key1.last < key2.last;    
        else
            return key1.first < key2.first;

    }
};

int main() {
    map<Key,Value,Comp> m;
    m[Key("doe","john")] = Value("1234 Main Street","Dearborn","12345");
    m[Key("doe","jane")] = Value("4321 Center Street","Peoria","23451");
    m[Key("dough","jim")] = Value("2341 State Street","Denver","65432");
    
    for (auto& [k, v]: m)        // Structured Binding (C++ 2017)
        cout << k.last << ' ' << k.first << ' ' << v.address << ' '
             << v.city << ' ' << v.zip << endl;
}

/* Output
doe jane 4321 Center Street Peoria 23451
doe john 1234 Main Street Dearborn 12345
dough jim 2341 State Street Denver 65432
*/
