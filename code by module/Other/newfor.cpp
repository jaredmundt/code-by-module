#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    array<int,3> a = {10, 20, 30};
    vector<int> v(a.begin(), a.end());
    
    for (int n : a)
        cout << n << '\n';
        
    for (int e : v)
        cout << e << '\n';
        
    for (int& n : a)
        n = -n;
    
    for (int n : a)
        cout << n << '\n';
}

/* Output:
10
20
30
10
20
30
-10
-20
-30
*/
