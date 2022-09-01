#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>
using namespace std;

void f(const vector<int>& v) {
    copy(begin(v),end(v),ostream_iterator<int>(cout," "));
    cout << endl;
}

struct Foo {
    Foo(const string& s, int i) {
        cout << "Foo with " << s << " and " << i << endl;
    }
};

int main() {
    int x{7};
    cout << x << endl;
    int a[]{1,2,3};
    copy(begin(a),end(a),ostream_iterator<int>(cout," "));
    cout << endl;
    vector v{1,2,3};
    copy(begin(v),end(v),ostream_iterator<int>(cout," "));
    cout << endl;
    v = {4,5,6};
    copy(begin(v),end(v),ostream_iterator<int>(cout," "));
    cout << endl;
    v.insert(end(v),{7,8,9});
    copy(begin(v),end(v),ostream_iterator<int>(cout," "));
    cout << endl;
    Foo foo{"one",1};
    map<string,int> m{{"one",1},{"two",2}};
    for (const auto& p: m)
        cout << p.first << "," << p.second << endl;
    f({1,2,3});     // initializer_list
}

/* Output:
7
1 2 3 
1 2 3 
4 5 6 
4 5 6 7 8 9 
Foo with one and 1
one,1
two,2
1 2 3 
*/