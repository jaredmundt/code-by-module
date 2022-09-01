// Shows compile-time computation
#include <iostream>
using namespace std;

constexpr unsigned long long factorial(unsigned long long n) {
	return n <= 1 ? 1 : n * factorial(n-1);
}

int main() {
	int a[factorial(5)];
	cout << sizeof(a)/sizeof(a[0]) << '\n';
	static_assert(factorial(6) == 720);	// Change value and observe compiler error
	
    // Compile-time computation (20 is a literal)
	unsigned long long v = factorial(20);
	cout << v << '\n';

    // Runtime computation (n is an lvalue)
    int n = 10;
    cout << factorial(n) << '\n';
}

/* Output:
120
2432902008176640000
3628800
*/
