#include <functional>
#include <iostream>
using namespace std;

int main() {
    function<int(int)> fib = [&fib](int n) {return n < 2 ? n : fib(n-1) + fib(n-2);};
    for (auto n: {0,1,2,3,4,5})
        cout << fib(n) << endl;
}

/* Output:
0
1
1
2
3
5
*/
