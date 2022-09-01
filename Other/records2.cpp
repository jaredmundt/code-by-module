// Defines a strict-weak comparator for a set of records

#include <set>
#include <iostream>
#include <string>
using namespace std;

struct Record {
    string last;
    string first;
    string address;
    string city;
    string zip;
};

struct Comp {
    bool operator()(const Record& key1, const Record& key2) const {
        if (key1.last == key2.last)
            return key1.first < key2.first;
        else
            return key1.last < key2.last;
    }
};

int main() {
    set<Record,Comp> m;
    m.insert(Record{"dough","jim","2341 State Street","Denver","65432"});
    m.insert(Record{"doe","john","1234 Main Street","Dearborn","12345"});
    m.insert(Record{"doe","jane","4321 Center Street","Peoria","23451"});
    
    for (auto &x: m)
        cout << x.last << ' ' << x.first << ' ' << x.address << ' '
             << x.city << ' ' << x.zip << endl;
}

/* Output
doe jane 4321 Center Street Peoria 23451
doe john 1234 Main Street Dearborn 12345
dough jim 2341 State Street Denver 65432
*/
