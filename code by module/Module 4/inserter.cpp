#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<unsigned int> v1;
    generate_n(back_inserter(v1), 10, [](){return rand()%10;});
    copy(begin(v1), end(v1), ostream_iterator<unsigned int>(cout, " "));
    cout << endl;
    
    vector<unsigned int> v2;
    transform(begin(v1), end(v1), back_inserter(v2), [](int n){return n+10;});
    copy(begin(v2), end(v2), ostream_iterator<unsigned int>(cout, " "));
    cout << endl;
    
    transform(begin(v2), end(v2), begin(v2), [](int n){return n+1;});
    copy(begin(v2), end(v2), ostream_iterator<unsigned int>(cout, " "));
    cout << endl;

    cout << accumulate(begin(v2), end(v2), 0) << endl;
    cout << fixed;
    cout << accumulate(begin(v2), end(v2), 1.0, [](double m, double n){return m*n;}) << endl;
    
    string stuff[] = {"go","ahead","make","my","day"};
    cout << accumulate(begin(stuff),end(stuff),string("")) << endl;
}

/* Output:
7 9 3 8 0 2 4 8 3 9 
17 19 13 18 10 12 14 18 13 19 
18 20 14 19 11 13 15 19 14 20 
163
1092755664000.000000
goaheadmakemyday
*/
