#include <iostream>
using namespace std;

// Primary template
template<int n, template<int> class F>
struct Accumulate {
   enum {val = Accumulate<n-1, F>::val + F<n>::val};
};

// Base specialization (to end the recursive instantiation)
template<template<int> class F>
struct Accumulate<0, F> {
   enum {val = F<0>::val};
};

// Sample template computations
template<int n>
struct Identity {
   enum {val = n};
};

template<int n>
struct Square {
   enum {val = n*n};
};

template<int n>
struct Cube {
   enum {val = n*n*n};
};

int main() {
   cout << Accumulate<4, Identity>::val << endl;
   cout << Accumulate<4, Square>::val << endl;
   cout << Accumulate<4, Cube>::val << endl;
}

/* Output:
10
30
100
*/


