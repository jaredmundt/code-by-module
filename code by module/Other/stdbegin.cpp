#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    int a[] = {1,1,2,3,5,8};
    copy(a,a+6,ostream_iterator<int>(cout, " "));
    cout << endl;

    copy(begin(a),end(a),ostream_iterator<int>(cout, " "));
    cout << endl;    
    
    vector<int> v{1,1,2,3,5,8};
    copy(begin(v),end(v),ostream_iterator<int>(cout, " "));
    cout << endl;    
}