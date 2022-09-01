#include <cassert>
#include <iostream>
using namespace std;

// Primary Template
template<int n>
struct Factorial {
   enum {val = Factorial<n-1>::val * n};
};

// Terminating specialization
template<>
struct Factorial<0> {
   enum {val = 1};
};

int main() {
   cout << Factorial<12>::val << endl;
   cout << Factorial<1>::val << endl;
   cout << Factorial<2>::val << endl;
   cout << Factorial<3>::val << endl;
   double nums[Factorial<5>::val];
   static_assert(sizeof nums == sizeof(double)*120,"dimension error");
   cout << sizeof(nums) << endl;     
}

/* Output:
479001600
1
2
6
960
*/
