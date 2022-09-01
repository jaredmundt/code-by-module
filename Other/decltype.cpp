#include <iostream>
#include <typeinfo>
using namespace std;

auto f(int x)->int {
    return x*x;
}

template<typename T1, typename T2>
auto min(T1 t1, T2 t2)->decltype(t1+t2) {   // Promote to wider type
    return t1 < t2 ? t1 : t2;
} 

int main() {
    cout << f(3) << endl;
    auto x = min(1.1, 2);
    cout << x << ", " << typeid(x).name() << endl;
}

/* Output:
9
1.1, d
*/