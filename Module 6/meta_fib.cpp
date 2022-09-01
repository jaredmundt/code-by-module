#include <iostream>
using namespace std;

// Primary template
template<int n>
struct Fib {
   enum {val = Fib<n-1>::val + Fib<n-2>::val};
};

// Base case for 1
template<>
struct Fib<1> {
   enum {val = 1};
};

// Base case for 0
template<>
struct Fib<0> {
   enum {val = 0};
};

int main() {
   cout << Fib<5>::val << endl;   // 5
   cout << Fib<20>::val << endl;  // 6765
}

