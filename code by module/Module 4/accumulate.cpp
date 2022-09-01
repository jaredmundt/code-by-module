// accumulate.cpp: Illustrates std::accumulate
#include <array>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
    array<int,5> nums = {1,2,3,4,5};
    cout << "sum = " << accumulate(begin(nums),end(nums),0) << endl;
    auto mult = [](int sofar, int next){return sofar*next;};
    cout << "product = " << accumulate(begin(nums),end(nums),1,mult) << endl;
    
    // Try with an empty array
    array<int,0> empty;
    cout << "sum = " << accumulate(begin(empty),end(empty),0) << endl;
    cout << "product = " << accumulate(begin(empty),end(empty),1,mult) << endl;
}

/* Output:
sum = 15
product = 120
sum = 0
product = 1
*/
