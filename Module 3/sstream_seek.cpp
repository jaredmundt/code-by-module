#include <cassert>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int n;
    double x;
    string s;

    {
        s = "10.21";
        istringstream is1(s);
        is1 >> x;
        cout << x << endl;
        is1.clear();
        is1.seekg(0,ios::beg);
        is1 >> n;
        cout << n << endl;
    }

    {
        s = "123";
        istringstream os2(s);
        int n;
        os2 >> n;
        cout << n << endl;
    }

    stringstream ss(ios::in | ios::out);
    ss << "21.01";
    ss.seekg(0, ios::beg);
    ss >> x;
    ss.clear(); // Important!
    cout << x << endl;
    ss.seekp(0, ios::beg);
    ss << "321";
    ss.seekg(0, ios::beg);
    ss >> n;
    cout << n << endl;

    ss.clear();
    ss.seekp(0, ios::beg);
    ss << "321x";           // Note where the put pointer is!
    ss.seekg(0, ios::beg);
    ss >> n;
    cout << n << endl;

    ss << "999 ";
    cout << ss.str() << endl;
}

/* Output:
10.21
10
123
21.01
32101
321
321x999
*/
