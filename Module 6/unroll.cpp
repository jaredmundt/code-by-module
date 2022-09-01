#include <iostream>
using namespace std;

template<int n>
inline int power(int m)
{
   return power<n-1>(m) * m;
}

template<>
inline int power<1>(int m)
{
   return m;
}

template<>
inline int power<0>(int m)
{
   return 1;
}

// Because the code is inlined, the statement below is equivalent to
// 
// cout << m * m * m << endl;
//
// which is very efficient. The power must be a non-negative, 
// compile-time constant, of course.

int main()
{
   int m = 4;
   cout << power<3>(m) << endl;
}

/* Output:
64
*/

