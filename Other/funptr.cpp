#include <cassert>
#include <iostream>
using namespace std;

int mymax(int x, int y) {
    return x > y ? x : y;   // Return the max
}

int mymin(int x, int y) {
    return x < y ? x : y;   // Return the min
}

int extremum(int* a, int n, int f(int,int)) {   // Or , int (*f)(int,int)
    assert(n > 0);
    int result = a[0];
    for (int i = 1; i < n; ++i)
        result = f(result,a[i]);
    return result;
}

int main() {
    int a[] = {1,2,3,4,5};
    cout << extremum(a,5,mymax) << endl;    // 5
    int (*pf1)(int,int) = &mymin;           // & optional
    cout << extremum(a,5,pf1) << endl;      // 1
    auto pf2 = mymin;                       // & optional (missing here)
    cout << extremum(a,5,pf2) << endl;      // 1
    decltype(mymin) *pf3 = mymin;           // * NOT optional in a declaration; pf3 is a pointer to a function
    cout << extremum(a,5,pf3) << endl;      // 1
}    

/* Output:
5
1
1
1
*/
 