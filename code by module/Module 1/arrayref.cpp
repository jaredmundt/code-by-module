#include <iostream>
using namespace std;

template<typename T, size_t N>
void f(T (&a)[N]) {
    cout << "size: " << sizeof a << endl;
    a[1] *= 10;
    for (auto x: a) 
    	cout << x << endl;
}

int main() {
    int nums[]{1,2,3,4,5}; 
    f(nums);
}

/* Output:
size: 20
1
20
3
4
5
*/
